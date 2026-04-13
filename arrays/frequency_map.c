#include <stdio.h>
#include <stdlib.h>

struct MapNode {
    int key;
    int value;
    struct MapNode* next;
};

struct FrequencyMap {
    struct MapNode* head;
    int size;
};

int createFrequencyMap(struct FrequencyMap* map) {
    map = (struct FrequencyMap*)malloc(sizeof(struct FrequencyMap));
    if (NULL == map) {
        return -1;
    }
    
    map->head = NULL;
    map->size = 0;
    return 0;
}

void insert(struct FrequencyMap* map, int key) {
    struct MapNode* current = map->head;
    while (current != NULL) {
        if (current->key == key) {
            current->value++;
            return;
        }
        current = current->next;
    }
    
    struct MapNode* new_node = (struct MapNode*)malloc(sizeof(struct MapNode));
    if (NULL == new_node) {
        return; // Falha na alocação de memória
    }
    new_node->key = key;
    new_node->value = 1;
    new_node->next = map->head;
    map->head = new_node;
    map->size++;
}

void printFrequencyMap(struct FrequencyMap* map) {
    struct MapNode* current = map->head;
    while (current != NULL) {
        printf("Key: %d, Frequency: %d\n", current->key, current->value);
        current = current->next;
    }
}

int main(void) {

    struct FrequencyMap map;
    if (createFrequencyMap(&map) != 0) {
        fprintf(stderr, "Failed to create frequency map\n");
        return EXIT_FAILURE;
    }

    int arr[] = {1, 2, 2, 3, 3, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        insert(&map, arr[i]);
    }

    printFrequencyMap(&map);
    
    return EXIT_SUCCESS;

}