#!/usr/bin/env python3

import re
import subprocess
import sys

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


def main():
    lcf_path, command = sys.argv[1], sys.argv[2:]
    result = subprocess.run(command)
    if result.returncode != 0:
        sys.exit(result.returncode)
    with open(lcf_path, encoding="utf-8", newline="") as file:
        lcf = file.read()
    with open(lcf_path, "w", encoding="utf-8", newline="") as file:
        file.write(define_symbols(lcf))


if __name__ == "__main__":
    main()
