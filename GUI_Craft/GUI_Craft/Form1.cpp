#include "pch.h"
#include "Form1.h"

void CppCLRWinFormsProject::Form1::updateInventory(libitem li) {

}

void CppCLRWinFormsProject::Form1::tokenize(string const& str, const char delim, std::vector<string>& out) {
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

bool CppCLRWinFormsProject::Form1::checkSlotInventory(int i, int j) {
    Item* check = this->inventory->getItem(i, j);
    if (check->isEmpty()) {
        return false;
    }
    else {
        return true;
    }
}

bool CppCLRWinFormsProject::Form1::checkSlotCrafting(int i, int j) {
    Item* check = this->crafting->getItem(i, j);
    if (check->isEmpty()) {
        return false;
    }
    else {
        return true;
    }
}

void CppCLRWinFormsProject::Form1::RefreshGUI() {

    // REFRESH INVENTORY
    bool check = checkSlotInventory(0, 0);
    if (check) {
        Item* item0 = this->inventory->getItem(0, 0);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(0, 0)->getname() + " " + to_string(inventory->getItem(0, 0)->getquantity());
        }
        else {
            slotName = inventory->getItem(0, 0)->getname() + " " + to_string(inventory->getItem(0, 0)->getdurability());
        }
        this->I0->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I0->Text = "I0";
    }
    check = checkSlotInventory(0, 1);
    if (check) {
        Item* item0 = this->inventory->getItem(0, 1);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(0, 1)->getname() + " " + to_string(inventory->getItem(0, 1)->getquantity());
        }
        else {
            slotName = inventory->getItem(0, 1)->getname() + " " + to_string(inventory->getItem(0, 1)->getdurability());
        }
        this->I1->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I1->Text = "I1";
    }
    check = checkSlotInventory(0, 2);
    if (check) {
        Item* item0 = this->inventory->getItem(0, 2);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(0, 2)->getname() + " " + to_string(inventory->getItem(0, 2)->getquantity());
        }
        else {
            slotName = inventory->getItem(0, 2)->getname() + " " + to_string(inventory->getItem(0, 2)->getdurability());
        }
        this->I2->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I2->Text = "I2";
    }
    check = checkSlotInventory(0, 3);
    if (check) {
        Item* item0 = this->inventory->getItem(0, 3);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(0, 3)->getname() + " " + to_string(inventory->getItem(0, 3)->getquantity());
        }
        else {
            slotName = inventory->getItem(0, 3)->getname() + " " + to_string(inventory->getItem(0, 3)->getdurability());
        }
        this->I3->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I3->Text = "I3";
    }
    check = checkSlotInventory(0, 4);
    if (check) {
        Item* item0 = this->inventory->getItem(0, 4);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(0, 4)->getname() + " " + to_string(inventory->getItem(0, 4)->getquantity());
        }
        else {
            slotName = inventory->getItem(0, 4)->getname() + " " + to_string(inventory->getItem(0, 4)->getdurability());
        }
        this->I4->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I4->Text = "I4";
    }
    check = checkSlotInventory(0, 5);
    if (check) {
        Item* item0 = this->inventory->getItem(0, 5);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(0, 5)->getname() + " " + to_string(inventory->getItem(0, 5)->getquantity());
        }
        else {
            slotName = inventory->getItem(0, 5)->getname() + " " + to_string(inventory->getItem(0, 5)->getdurability());
        }
        this->I5->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I5->Text = "I5";
    }
    check = checkSlotInventory(0, 6);
    if (check) {
        Item* item0 = this->inventory->getItem(0, 6);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(0, 6)->getname() + " " + to_string(inventory->getItem(0, 6)->getquantity());
        }
        else {
            slotName = inventory->getItem(0, 6)->getname() + " " + to_string(inventory->getItem(0, 6)->getdurability());
        }
        this->I6->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I6->Text = "I6";
    }
    check = checkSlotInventory(0, 7);
    if (check) {
        Item* item0 = this->inventory->getItem(0, 7);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(0, 7)->getname() + " " + to_string(inventory->getItem(0, 7)->getquantity());
        }
        else {
            slotName = inventory->getItem(0, 7)->getname() + " " + to_string(inventory->getItem(0, 7)->getdurability());
        }
        this->I7->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I7->Text = "I0";
    }
    check = checkSlotInventory(0, 8);
    if (check) {
        Item* item0 = this->inventory->getItem(0, 8);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(0, 8)->getname() + " " + to_string(inventory->getItem(0, 8)->getquantity());
        }
        else {
            slotName = inventory->getItem(0, 8)->getname() + " " + to_string(inventory->getItem(0, 8)->getdurability());
        }
        this->I8->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I8->Text = "I8";
    }
    check = checkSlotInventory(1, 0);
    if (check) {
        Item* item0 = this->inventory->getItem(1, 0);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(1, 0)->getname() + " " + to_string(inventory->getItem(1, 0)->getquantity());
        }
        else {
            slotName = inventory->getItem(1, 0)->getname() + " " + to_string(inventory->getItem(1, 0)->getdurability());
        }
        this->I9->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I9->Text = "I9";
    }
    check = checkSlotInventory(1, 1);
    if (check) {
        Item* item0 = this->inventory->getItem(1, 1);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(1, 1)->getname() + " " + to_string(inventory->getItem(1, 1)->getquantity());
        }
        else {
            slotName = inventory->getItem(1, 1)->getname() + " " + to_string(inventory->getItem(1, 1)->getdurability());
        }
        this->I10->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I10->Text = "I10";
    }
    check = checkSlotInventory(1, 2);
    if (check) {
        Item* item0 = this->inventory->getItem(1, 2);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(1, 2)->getname() + " " + to_string(inventory->getItem(1, 2)->getquantity());
        }
        else {
            slotName = inventory->getItem(1, 2)->getname() + " " + to_string(inventory->getItem(1, 2)->getdurability());
        }
        this->I11->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I11->Text = "I11";
    }
    check = checkSlotInventory(1, 3);
    if (check) {
        Item* item0 = this->inventory->getItem(1, 3);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(1, 3)->getname() + " " + to_string(inventory->getItem(1, 3)->getquantity());
        }
        else {
            slotName = inventory->getItem(1, 3)->getname() + " " + to_string(inventory->getItem(1, 3)->getdurability());
        }
        this->I12->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I12->Text = "I12";
    }
    check = checkSlotInventory(1, 4);
    if (check) {
        Item* item0 = this->inventory->getItem(1, 4);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(1, 4)->getname() + " " + to_string(inventory->getItem(1, 4)->getquantity());
        }
        else {
            slotName = inventory->getItem(1, 4)->getname() + " " + to_string(inventory->getItem(1, 4)->getdurability());
        }
        this->I13->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I13->Text = "I13";
    }
    check = checkSlotInventory(1, 5);
    if (check) {
        Item* item0 = this->inventory->getItem(1, 5);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(1, 5)->getname() + " " + to_string(inventory->getItem(1, 5)->getquantity());
        }
        else {
            slotName = inventory->getItem(1, 5)->getname() + " " + to_string(inventory->getItem(1, 5)->getdurability());
        }
        this->I14->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I14->Text = "I14";
    }
    check = checkSlotInventory(1, 6);
    if (check) {
        Item* item0 = this->inventory->getItem(1, 6);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(1, 6)->getname() + " " + to_string(inventory->getItem(1, 6)->getquantity());
        }
        else {
            slotName = inventory->getItem(1, 6)->getname() + " " + to_string(inventory->getItem(1, 6)->getdurability());
        }
        this->I15->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I15->Text = "I15";
    }
    check = checkSlotInventory(1, 7);
    if (check) {
        Item* item0 = this->inventory->getItem(1, 7);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(1, 7)->getname() + " " + to_string(inventory->getItem(1, 7)->getquantity());
        }
        else {
            slotName = inventory->getItem(1, 7)->getname() + " " + to_string(inventory->getItem(1, 7)->getdurability());
        }
        this->I16->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I16->Text = "I16";
    }
    check = checkSlotInventory(1, 8);
    if (check) {
        Item* item0 = this->inventory->getItem(1, 8);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(1, 8)->getname() + " " + to_string(inventory->getItem(1, 8)->getquantity());
        }
        else {
            slotName = inventory->getItem(1, 8)->getname() + " " + to_string(inventory->getItem(1, 8)->getdurability());
        }
        this->I17->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I17->Text = "I17";
    }
    check = checkSlotInventory(2, 0);
    if (check) {
        Item* item0 = this->inventory->getItem(2, 0);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(2, 0)->getname() + " " + to_string(inventory->getItem(2, 0)->getquantity());
        }
        else {
            slotName = inventory->getItem(2, 0)->getname() + " " + to_string(inventory->getItem(2, 0)->getdurability());
        }
        this->I18->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I18->Text = "I18";
    }
    check = checkSlotInventory(2, 1);
    if (check) {
        Item* item0 = this->inventory->getItem(2, 1);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(2, 1)->getname() + " " + to_string(inventory->getItem(2, 1)->getquantity());
        }
        else {
            slotName = inventory->getItem(2, 1)->getname() + " " + to_string(inventory->getItem(2, 1)->getdurability());
        }
        this->I19->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I19->Text = "I19";
    }
    check = checkSlotInventory(2, 2);
    if (check) {
        Item* item0 = this->inventory->getItem(2, 2);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(2, 2)->getname() + " " + to_string(inventory->getItem(2, 2)->getquantity());
        }
        else {
            slotName = inventory->getItem(2, 2)->getname() + " " + to_string(inventory->getItem(2, 2)->getdurability());
        }
        this->I20->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I20->Text = "I20";
    }
    check = checkSlotInventory(2, 3);
    if (check) {
        Item* item0 = this->inventory->getItem(2, 3);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(2, 3)->getname() + " " + to_string(inventory->getItem(2, 3)->getquantity());
        }
        else {
            slotName = inventory->getItem(2, 3)->getname() + " " + to_string(inventory->getItem(2, 3)->getdurability());
        }
        this->I21->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I21->Text = "I21";
    }
    check = checkSlotInventory(2, 4);
    if (check) {
        Item* item0 = this->inventory->getItem(2, 4);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(2, 4)->getname() + " " + to_string(inventory->getItem(2, 4)->getquantity());
        }
        else {
            slotName = inventory->getItem(2, 4)->getname() + " " + to_string(inventory->getItem(2, 4)->getdurability());
        }
        this->I22->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I22->Text = "I22";
    }
    check = checkSlotInventory(2, 5);
    if (check) {
        Item* item0 = this->inventory->getItem(2, 5);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(2, 5)->getname() + " " + to_string(inventory->getItem(2, 5)->getquantity());
        }
        else {
            slotName = inventory->getItem(2, 5)->getname() + " " + to_string(inventory->getItem(2, 5)->getdurability());
        }
        this->I23->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I23->Text = "I23";
    }
    check = checkSlotInventory(2, 6);
    if (check) {
        Item* item0 = this->inventory->getItem(2, 6);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(2, 6)->getname() + " " + to_string(inventory->getItem(2, 6)->getquantity());
        }
        else {
            slotName = inventory->getItem(2, 6)->getname() + " " + to_string(inventory->getItem(2, 6)->getdurability());
        }
        this->I24->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I24->Text = "I24";
    }
    check = checkSlotInventory(2, 7);
    if (check) {
        Item* item0 = this->inventory->getItem(2, 7);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(2, 7)->getname() + " " + to_string(inventory->getItem(2, 7)->getquantity());
        }
        else {
            slotName = inventory->getItem(2, 7)->getname() + " " + to_string(inventory->getItem(2, 7)->getdurability());
        }
        this->I25->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I25->Text = "I25";
    }
    check = checkSlotInventory(2, 8);
    if (check) {
        Item* item0 = this->inventory->getItem(2, 8);
        string slotName;
        if (item0->isNonTool()) {
            slotName = inventory->getItem(2, 8)->getname() + " " + to_string(inventory->getItem(2, 8)->getquantity());
        }
        else {
            slotName = inventory->getItem(2, 8)->getname() + " " + to_string(inventory->getItem(2, 8)->getdurability());
        }
        this->I26->Text = gcnew System::String(slotName.data());
    }
    else {
        this->I26->Text = "I26";
    }

    // REFRESH CRAFTING TABLE
    check = checkSlotCrafting(0, 0);
    if (check) {
        Item* item0 = this->crafting->getItem(0, 0);
        string slotName;
        if (item0->isNonTool()) {
            slotName = crafting->getItem(0, 0)->getname() + " " + to_string(crafting->getItem(0, 0)->getquantity());
        }
        else {
            slotName = crafting->getItem(0, 0)->getname() + " " + to_string(crafting->getItem(0, 0)->getdurability());
        }
        this->C0->Text = gcnew System::String(slotName.data());
    }
    else {
        this->C0->Text = "C0";
    }
    check = checkSlotCrafting(0, 1);
    if (check) {
        Item* item0 = this->crafting->getItem(0, 1);
        string slotName;
        if (item0->isNonTool()) {
            slotName = crafting->getItem(0, 1)->getname() + " " + to_string(crafting->getItem(0, 1)->getquantity());
        }
        else {
            slotName = crafting->getItem(0, 1)->getname() + " " + to_string(crafting->getItem(0, 1)->getdurability());
        }
        this->C1->Text = gcnew System::String(slotName.data());
    }
    else {
        this->C1->Text = "C1";
    }
    check = checkSlotCrafting(0, 2);
    if (check) {
        Item* item0 = this->crafting->getItem(0, 2);
        string slotName;
        if (item0->isNonTool()) {
            slotName = crafting->getItem(0, 2)->getname() + " " + to_string(crafting->getItem(0, 2)->getquantity());
        }
        else {
            slotName = crafting->getItem(0, 2)->getname() + " " + to_string(crafting->getItem(0, 2)->getdurability());
        }
        this->C2->Text = gcnew System::String(slotName.data());
    }
    else {
        this->C2->Text = "C2";
    }
    check = checkSlotCrafting(1, 0);
    if (check) {
        Item* item0 = this->crafting->getItem(1, 0);
        string slotName;
        if (item0->isNonTool()) {
            slotName = crafting->getItem(1, 0)->getname() + " " + to_string(crafting->getItem(1, 0)->getquantity());
        }
        else {
            slotName = crafting->getItem(1, 0)->getname() + " " + to_string(crafting->getItem(1, 0)->getdurability());
        }
        this->C3->Text = gcnew System::String(slotName.data());
    }
    else {
        this->C3->Text = "C3";
    }
    check = checkSlotCrafting(1, 1);
    if (check) {
        Item* item0 = this->crafting->getItem(1, 1);
        string slotName;
        if (item0->isNonTool()) {
            slotName = crafting->getItem(1, 1)->getname() + " " + to_string(crafting->getItem(1, 1)->getquantity());
        }
        else {
            slotName = crafting->getItem(1, 1)->getname() + " " + to_string(crafting->getItem(1, 1)->getdurability());
        }
        this->C4->Text = gcnew System::String(slotName.data());
    }
    else {
        this->C4->Text = "C4";
    }
    check = checkSlotCrafting(1, 2);
    if (check) {
        Item* item0 = this->crafting->getItem(1, 2);
        string slotName;
        if (item0->isNonTool()) {
            slotName = crafting->getItem(1, 2)->getname() + " " + to_string(crafting->getItem(1, 2)->getquantity());
        }
        else {
            slotName = crafting->getItem(1, 2)->getname() + " " + to_string(crafting->getItem(1, 2)->getdurability());
        }
        this->C5->Text = gcnew System::String(slotName.data());
    }
    else {
        this->C5->Text = "C5";
    }
    check = checkSlotCrafting(2, 0);
    if (check) {
        Item* item0 = this->crafting->getItem(2, 0);
        string slotName;
        if (item0->isNonTool()) {
            slotName = crafting->getItem(2, 0)->getname() + " " + to_string(crafting->getItem(2, 0)->getquantity());
        }
        else {
            slotName = crafting->getItem(2, 0)->getname() + " " + to_string(crafting->getItem(2, 0)->getdurability());
        }
        this->C6->Text = gcnew System::String(slotName.data());
    }
    else {
        this->C6->Text = "C6";
    }
    check = checkSlotCrafting(2, 1);
    if (check) {
        Item* item0 = this->crafting->getItem(2, 1);
        string slotName;
        if (item0->isNonTool()) {
            slotName = crafting->getItem(2, 1)->getname() + " " + to_string(crafting->getItem(2, 1)->getquantity());
        }
        else {
            slotName = crafting->getItem(2, 1)->getname() + " " + to_string(crafting->getItem(2, 1)->getdurability());
        }
        this->C7->Text = gcnew System::String(slotName.data());
    }
    else {
        this->C7->Text = "C7";
    }
    check = checkSlotCrafting(2, 2);
    if (check) {
        Item* item0 = this->crafting->getItem(2, 2);
        string slotName;
        if (item0->isNonTool()) {
            slotName = crafting->getItem(2, 2)->getname() + " " + to_string(crafting->getItem(2, 2)->getquantity());
        }
        else {
            slotName = crafting->getItem(2, 2)->getname() + " " + to_string(crafting->getItem(2, 2)->getdurability());
        }
        this->C8->Text = gcnew System::String(slotName.data());
    }
    else {
        this->C8->Text = "C8";
    }
}