#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    const char *s_to_test;
    int expected_result;
} TestCase;

typedef struct _map_node
{
    char key;
    int value;
    struct _map_node *next;
} MapNode;

typedef struct
{
    MapNode *head;
} Map;

int create_map(Map **map)
{
    *map = (Map *)malloc(sizeof(Map));
    if (NULL == *map)
    {
        return -1;
    }

    (*map)->head = NULL;
    return 0;
}

int map_get(Map *map, char key, int _default);
int map_put(Map *map, char key, int value);
void map_drop(Map *map);

int maximum_length_substr(const char *s)
{
    int max = 0;
    const char *left = s, *right = s;
    Map *counter;

    if (create_map(&counter))
    {
        return -1;
    }

    while (*right != '\0')
    {
        map_put(counter, *right, map_get(counter, *right, 0) + 1);

        while (map_get(counter, *right, 0) == 3)
        {
            map_put(counter, *left, map_get(counter, *left, 0) - 1);
            left++;
        }

        int current_window_size = right - left + 1;
        if (current_window_size > max)
        {
            max = current_window_size;
        }

        right++;
    }

    map_drop(counter);
    return max;
}

int main(void)
{

    TestCase cases[] = {
        {"aaaa", 2},
        {"aaabb", 4},
        {"bcbbbcba", 4},
        {"", 0},
        {"abcdef", 6},
        {"aabbccade", 8}};

    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        int result = maximum_length_substr(cases[i].s_to_test);

        if (result == cases[i].expected_result)
        {
            printf("PASS: %s\n", cases[i].s_to_test);
        }
        else
        {
            printf("FAIL: %s (Expected %d, got %d)\n",
                   cases[i].s_to_test, cases[i].expected_result, result);
        }
    }
    return 0;
}

int map_get(Map *map, char key, int _default)
{
    MapNode *node = map->head;
    while (node != NULL)
    {
        if (node->key == key)
            return node->value;
        node = node->next;
    }
    return _default;
}

int map_put(Map *map, char key, int value)
{
    MapNode *node = map->head;
    while (node != NULL)
    {
        if (node->key == key)
        {
            node->value = value;
            return 0;
        }
        node = node->next;
    }

    MapNode *new_node = (MapNode *)malloc(sizeof(MapNode));
    if (new_node == NULL)
        return -1;

    new_node->key = key;
    new_node->value = value;
    new_node->next = map->head;
    map->head = new_node;
    return 0;
}

void map_drop(Map *map)
{
    MapNode *node = map->head;
    while (node != NULL)
    {
        MapNode *aux = node;
        node = node->next;
        free(aux);
    }

    free(map);
}