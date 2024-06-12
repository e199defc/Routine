/*
 * Hash Table
 * Link List
 */

#define HASH_SIZE 1000

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node;

typedef struct
{
    Node **table;
    int size;
} HashTable;

#define bool int
#define true 1
#define false 0

bool initHashTable(HashTable **table, int size);
bool freeTable(HashTable *table);
bool newNode(Node **node, int key, int value);
int hashFunction(int key, int size);
bool insert(HashTable *table, int key, int value);
bool get(HashTable *table, int key, int *value);
int *twoSum(int *nums, int numsSize, int target, int *returnSize);

bool initHashTable(HashTable **table, int size)
{
    // When passing a pointer to a function, it shares the same address in memory. However, if the goal is to modify the pointer itself, include the `&` symbol when passing the parameter, and employ `**` in the declaration.

    if (size <= 0)
    {
        return false; // Verify if an integer has a *negative* value.
    }

    HashTable *newTable = NULL;
    *table = NULL; // Assigning NULL directly to a pointer type parameter at first.

    if ((newTable = (HashTable *)malloc(sizeof(HashTable))) == NULL)
    {
        return false; // Always check if `malloc()` returns NULL when creating memory.
    }
    if ((newTable->table = (Node **)malloc(size * sizeof(Node *))) == NULL)
    {
        free(newTable);  // Use `free()` in conjunction with `malloc()`.
        newTable = NULL; // Set a pointer to NULL after freeing its memory.
        return false;
    }

    memset(newTable->table, 0, size * sizeof(Node *)); // Ensure to initialize allocated memory to zero with `memset` in `<string.h>` when using a linked list.
    newTable->size = size;
    *table = newTable;

    return true;
}

bool freeTable(HashTable *table)
{
    if (!table)
    {
        return true; // Verify whether the pointer is initially pointing to NULL.
    }

    int i = -1;
    Node *pre = NULL;
    Node *cur = NULL;

    for (i = 0; i < table->size; ++i)
    {
        cur = table->table[i];
        while (cur != NULL)
        {
            pre = cur;
            cur = cur->next;
            free(pre);
            pre = NULL;
        }
    }

    free(table);
    table = NULL;
    return true;
}

bool newNode(Node **node, int key, int value)
{
    Node *newNode;
    *node = NULL;

    if ((newNode = (Node *)malloc(sizeof(Node))) == NULL)
    {
        return false;
    }

    newNode->key = key;
    newNode->next = NULL;
    newNode->value = value;
    *node = newNode;
    return true;
}

int hashFunction(int key, int size)
{
    key = key < 0 ? -key : key;
    return (key * 11 + 13) % size;
}

bool insert(HashTable *table, int key, int value)
{
    if (!table)
    {
        return false;
    }

    int index = -1;
    Node *cur = NULL;
    Node *node = NULL;

    if (newNode(&node, key, value) == false) // Identify a true return value indicating success.
    {
        return false;
    }

    index = hashFunction(key, table->size);

    if (table->table[index] == NULL) // When the head node is empty, avoid using a variable to represent the head node and assigning the pointer directly.
    {
        table->table[index] = node;
        return true;
    }

    cur = table->table[index];

    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = node;
    return true;
}

bool get(HashTable *table, int key, int *value)
{
    if (!table && !value)
    {
        return false;
    }

    int index = -1;
    Node *cur = NULL;

    index = hashFunction(key, HASH_SIZE);
    cur = table->table[index];

    while (cur != NULL)
    {
        if (cur->key == key)
        {
            *value = cur->value;
            return true;
        }
        cur = cur->next; // Multiple keys mapping to the same index.
    }
    return false;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i = -1;
    int value = -1;
    int *result = NULL;
    HashTable *table = NULL;

    *returnSize = 0;

    if (nums == NULL || returnSize == NULL || numsSize <= 0)
    {
        return NULL;
    }

    if ((result = (int *)malloc(2 * sizeof(int))) == NULL)
    {
        return NULL;
    }

    if (initHashTable(&table, HASH_SIZE) == false)
    {
        free(result);
        result = NULL;
        return NULL;
    }

    for (i = 0; i < numsSize; ++i)
    {
        // Create a hash table with corresponding indices as values and index values as keys. Retrieve the corresponding index when the value appears.
        if (get(table, nums[i], &value))
        {
            result[0] = value;
            result[1] = i;
            *returnSize = 2; // Verify that return values are set correctly.
            freeTable(table);
            return result;
        }
        insert(table, target - nums[i], i);
    }

    // Always handle failure scenarios appropriately.
    freeTable(table);
    free(result);
    result = NULL;
    return NULL;
}
