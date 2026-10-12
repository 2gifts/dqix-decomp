struct RedrawLayer0222f9ec {
    unsigned char pad[8];
    unsigned short* rows;
    unsigned char padc[8];
    void* display;
};
struct RedrawHolder0222f9ec {
    unsigned char pad[4];
    unsigned short position;
    unsigned char pad6[2];
    RedrawLayer0222f9ec* layer;
};
extern RedrawHolder0222f9ec data_ov031_02290ca0;
extern const unsigned short data_ov031_02248f96[9];
extern "C" int FastIntDivide(int, int);
extern "C" void CallVTableField14_0223ca40(void*, int);
extern "C" void func_ov031_0222faac(int, int);
extern "C" void func_ov031_0222fc48(int, int);
extern "C" void func_ov031_02234f4c(void*, int, int, int);
extern "C" void func_ov031_02230120(void);
void SetField604_02234f34(void);
void SetFlagIfMatchesElem0_0223caec(void*);

// USA: func_ov031_0222f9ec
extern "C" void func_ov031_0222f9ec(void) {
    int first = FastIntDivide(data_ov031_02290ca0.position, 29);
    CallVTableField14_0223ca40(data_ov031_02290ca0.layer->display, 0);
    int item = first;
    int index = 0;
    do {
        func_ov031_0222faac(item, index);
        ++index;
        ++item;
    } while (index < 5);
    func_ov031_02234f4c(data_ov031_02290ca0.layer->rows + data_ov031_02248f96[first], 0, 30, 19);
    int secondIndex = 0;
    do {
        func_ov031_0222fc48(first, secondIndex);
        ++secondIndex;
        ++first;
    } while (secondIndex < 5);
    SetField604_02234f34();
    SetFlagIfMatchesElem0_0223caec(data_ov031_02290ca0.layer->display);
    func_ov031_02230120();
}
