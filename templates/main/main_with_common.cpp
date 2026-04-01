#include <iostream>

#include "common/common.h"

int main() {
    ListNode* head = build_linked_list({1, 2, 3});
    std::cout << "head value: " << head->val << std::endl;
    delete_linked_list(head);

    return 0;
}
