#include "Inventory.hpp"

int main() {
    Inventory I;
    LibItem2 LI;

    LI.addToLibrary(1, "BIRCH_LOG", "LOG", false);
    LI.addToLibrary(2, "OAK_LOG", "LOG", false);
    LI.addToLibrary(24, "WOODEN_PICKAXE", "WOODEN", true);
   
    I.giveItem(LI, "BIRCH_LO", 20);
    I.giveItem(LI, "OAK_LOG", 20);
   
    I.giveItem(LI, "BIRCH_LOG", 20);
    
    I.printInventory();
}