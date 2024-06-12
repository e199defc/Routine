/*
 * Two Dimensional Pointer
 */

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1 && !l2) // Corresponds to `l1 == NULL || l2 == NULL`
        return NULL;

    int sum = 0;
    int carry = 0;
    struct ListNode *l3 = NULL;
    struct ListNode **ptr = &l3; // A pointer can be dereferenced by a pointer to a pointer, even if the original pointer is initialized to NULL.
    struct ListNode *newNode = NULL;

    while (l1 || l2 || carry > 0)
    {
        sum = carry;

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        if ((newNode = (struct ListNode *)malloc(sizeof(struct ListNode))) == NULL)
        {
            return NULL;
        }

        newNode->val = sum % 10;
        newNode->next = NULL;
        carry = sum / 10;
        *ptr = newNode;
        ptr = &(*ptr)->next;
    }

    return l3;
}
