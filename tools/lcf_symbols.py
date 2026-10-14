#!/usr/bin/env python3

import re
import subprocess
import sys
from pathlib import Path

SYMBOLS = {
    "SDK_IRQ_STACKSIZE": 0x400,
    "SDK_SYS_STACKSIZE": 0,
}


def define_symbols(lcf: str) -> str:
    sections = re.search(r"^SECTIONS \{(\r?\n)", lcf, re.MULTILINE)
    if sections is None:
        raise ValueError("no 'SECTIONS {' line in the linker script")
    newline = sections.group(1)
    body = lcf[sections.end():]
    definitions = "".join(f"    {name} = {value:#x};{newline}" for name, value in SYMBOLS.items()
                          if not re.search(rf"^\s*{name}\s*=", body, re.MULTILINE))
    return lcf[:sections.end()] + definitions + body


def preserve_rodata_boundaries(lcf: str, config_path: str) -> str:
    """Keep raw tails at their declared address after non-word-sized inputs."""
    root = Path(config_path).parent
    newline = "\r\n" if "\r\n" in lcf else "\n"
    for path in sorted(root.rglob("delinks.txt")):
        module = "ARM9" if path.parent == root else path.parent.name.upper()
        raw_prefix = "main" if path.parent == root else path.parent.name
        lines = path.read_text().splitlines()
        owned_objects = {Path(line[:-1]).stem + ".o" for line in lines
                         if line and not line[0].isspace() and line.endswith(":")}
        owner = None
        for line in lines:
            if line and not line[0].isspace() and line.endswith(":"):
                owner = line[:-1]
            match = re.fullmatch(r"\s+\.rodata\s+start:0x[0-9a-fA-F]+\s+end:0x([0-9a-fA-F]+)(?:\s+.*)?", line)
            if not owner or not match:
                continue
            end = int(match[1], 16)
            if end % 4 == 0:
                continue
            alignment = min(4, end & -end)
            section = re.search(rf"\b{module}_RODATA_START = \.;(.*?)\b{module}_RODATA_END = \.;", lcf, re.DOTALL)
            if section is None:
                raise ValueError(f"missing {module} rodata section")
            obj = re.escape(Path(owner).stem + ".o")
            pattern = rf"(?m)^([ \t]*)({obj}\(\.rodata\)){newline}([ \t]*)({re.escape(raw_prefix)}_[0-9]+\.o\(\.rodata\)){newline}"
            block = section[1]
            matches = list(re.finditer(pattern, block))
            if len(matches) != 1:
                raise ValueError(f"expected one raw rodata tail after {owner}")
            tail = matches[0]
            if tail[4].split("(", 1)[0] in owned_objects:
                raise ValueError(f"next rodata input after {owner} is source-owned")
            replacement = (tail[1] + tail[2] + newline + tail[3] + f"ALIGNALL({alignment});" + newline
                           + tail[3] + tail[4] + newline + tail[3] + "ALIGNALL(4);" + newline)
            block = block[:tail.start()] + replacement + block[tail.end():]
            lcf = lcf[:section.start(1)] + block + lcf[section.end(1):]
    return lcf


def main():
    lcf_path, command = sys.argv[1], sys.argv[2:]
    config_flag = "--config-path" if "--config-path" in command else "-c"
    config_path = command[command.index(config_flag) + 1]
    result = subprocess.run(command)
    if result.returncode != 0:
        sys.exit(result.returncode)
    with open(lcf_path, encoding="utf-8", newline="") as file:
        lcf = file.read()
    with open(lcf_path, "w", encoding="utf-8", newline="") as file:
        file.write(preserve_rodata_boundaries(define_symbols(lcf), config_path))


if __name__ == "__main__":
    main()
