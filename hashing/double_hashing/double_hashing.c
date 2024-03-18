#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int PRIME = 11;

void initialize(int *hash_table, int table_size)
{
    for (int i = 0; i < table_size; i++)
        hash_table[i] = -1;
}

void insert(int *hash_table, int table_size, int *keys_present, int value)
{

    if (value == -1 || value == -2)
    {
        printf("ERROR : -1 and -2 can't be inserted in the table\n");
    }

    if (table_size == *keys_present)
    {
        printf("ERROR : Hash Table Full\n");
        return;
    }

    int probe = (value % table_size), offset = (PRIME - (value % PRIME));

    while (hash_table[probe] != -1)
    {
        if (-2 == hash_table[probe])
            break; // insert at deleted element's location
        probe = (probe + offset) % table_size;
    }

    hash_table[probe] = value;
    *keys_present += 1;
}

bool search(int *hash_table, int table_size, int value)
{
    int probe = (value % table_size), offset = (PRIME - (value % PRIME)), initial_pos = probe;
    bool first_iteration = true;

    while (1)
    {
        if (hash_table[probe] == -1) // Stop search if -1 is encountered.
            break;
        else if (hash_table[probe] == value) // Stop search after finding the element.
            return true;
        else if (probe == initial_pos && !first_iteration) // Stop search if one complete traversal of hash table is completed.
            return false;
        else
            probe = ((probe + offset) % table_size); // if none of the above cases occur then update the index and check at it.

        first_iteration = false;
    }
    return false;
}

void delete(int *hash_table, int table_size, int *keys_present, int value)
{
    if (!search(hash_table, table_size, value))
        return;

    int probe = (value % table_size), offset = (PRIME - (value % PRIME));

    while (hash_table[probe] != -1)
        if (hash_table[probe] == value)
        {
            hash_table[probe] = -2; // mark element as deleted (rather than unvisited(-1)).
            *keys_present--;
            return;
        }
        else
            probe = (probe + offset) % table_size;
}

void print(int *hash_table, int table_size)
{
    for (int i = 0; i < table_size; i++)
        printf("%d, ", hash_table[i]);
    printf("\n");
}

int main()
{
    int table_size = 13;
    int hash_table[table_size];
    int keys_present = 0;

    initialize(hash_table, table_size);

    int insertions[] = {115, 12, 87, 66, 123},
        n1 = sizeof(insertions) / sizeof(insertions[0]);

    for (int i = 0; i < n1; i++)
        insert(hash_table, table_size, &keys_present, insertions[i]);

    int queries[] = {1, 12, 2, 3, 69, 88, 115},
        n2 = sizeof(queries) / sizeof(queries[0]);

    for (int i = 0; i < n2; i++)
        if (search(hash_table, table_size, queries[i]))
            printf("%d present\n", queries[i]);

    print(hash_table, table_size);
    int deletions[] = {123, 87, 66},
        n3 = sizeof(deletions) / sizeof(deletions[0]);

    for (int i = 0; i < n3; i++)
        delete (hash_table, table_size, &keys_present, deletions[i]);

    print(hash_table, table_size);
}