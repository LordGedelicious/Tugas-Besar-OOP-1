#include "LibItem.hpp"

int main() {
    LibItem ItemLibrary;

    // 1 BIRCH_LOG LOG NONTOOL
    ItemLibrary.addToLibrary(1, "BIRCH_LOG", "LOG", false);
    // 2 OAK_LOG LOG NONTOOL
    ItemLibrary.addToLibrary(2, "OAK_LOG", "LOG", false);


    // 24 WOODEN_PICKAXE WOODEN TOOL (gua saranin type tool juga dikasih)
    ItemLibrary.addToLibrary(24, "WOODEN_PICKAXE", "WOODEN", true);

    // 26 DIAMOND_PICKAXE - TOOL
    ItemLibrary.addToLibrary(26, "DIAMOND_PICKAXE", "DIAMOND", true);

    ItemLibrary.printAll();

    return 0;
}