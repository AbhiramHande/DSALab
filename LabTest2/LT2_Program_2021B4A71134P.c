#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list_node {
    int product_id;
    struct list_node* next;
};

struct transaction {
    struct list_node* data;
    struct transaction* next;
};

struct heap_node {
    int product_id;
    int count;
    struct transaction* data;
    struct heap_node* left;
    struct heap_node* right; 
};

struct heap {
    int size; //Both size and capacity for this question
    int depth;
    int* times;
    int* product;
};

typedef struct heap_node* leaf;
typedef struct list_node* node;
typedef struct transaction* transaction;
typedef struct heap* heap;

node create_new_list_node(int id) {
    node n = (node)malloc(sizeof(struct list_node));
    n->product_id = id;
    n->next = NULL;
    return n;
}

leaf create_new_heap_node(int id) {
    leaf n = (leaf)malloc(sizeof(struct heap_node));
    n->product_id = id;
    n->count = 0;
    n->data = NULL;
    n->left = NULL;
    n->right = NULL;
    return n;
}

transaction craete_new_transaction(int array[], int size) {
    transaction ll = (transaction)malloc(sizeof(struct transaction));
    ll->data = NULL;
    ll->next = NULL;

    while(size > 0) {
        node n = create_new_list_node(array[size-1]);
        n->next = ll->data;
        ll->data = n;
        size--;
    }

    return ll;
}

heap create_new_heap() {
    heap h = (heap)malloc(sizeof(struct heap));
    h->depth = 6;
    h->size = 100;
    h->product = calloc(100, sizeof(int));
    h->times = calloc(100, sizeof(int));

    for(int i = 0; i < 100; i++)
        h->product[i] = i+1;
    return h;
}

void print_transaction(transaction t){
    node ptr = t->data;
    while(ptr != NULL) {
        printf("%d ", ptr->product_id);
        ptr = ptr->next;
    }
}

void print_transactions(transaction t){
    while(t != NULL) {
        print_transaction(t);
        printf("\n");
        t = t->next;
    }
}

transaction createData() {
    transaction t = NULL;
    transaction temp;
    node n;

    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;


    //1 5 7 100
    n = create_new_list_node(100);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(7);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(5);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(1);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //74, 65, 62
    n = create_new_list_node(62);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(65);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(74);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //64 94 100 35 1
    n = create_new_list_node(1);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(35);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(100);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(64);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //67 87 94 100 45 98 23
    n = create_new_list_node(23);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(98);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(45);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(100);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(87);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(67);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //89 46 73 85 90
    n = create_new_list_node(90);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(85);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(73);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(46);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(89);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //83 74 82 2 5 94 10 32 25
    n = create_new_list_node(25);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(32);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(10);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(5);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(2);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(82);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(74);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(83);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //67
    n = create_new_list_node(67);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //68 56 93 92
    n = create_new_list_node(92);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(93);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(56);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(68);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //94 89 72 40
    n = create_new_list_node(40);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(72);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(89);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //98 94 68 95 100 57 48
    n = create_new_list_node(48);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(57);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(100);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(95);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(68);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(98);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //97 89 94 56 72
    n = create_new_list_node(72);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(56);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(89);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(97);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //100 99 98 97 6 5 94 76
    n = create_new_list_node(76);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(5);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(6);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(97);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(98);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(99);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(100);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //87 94 92 98 90 99
    n = create_new_list_node(99);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(90);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(98);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(92);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(87);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //64 28 47 95 10 75 38 36 100
    n = create_new_list_node(100);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(36);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(38);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(75);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(10);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(95);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(47);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(28);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(64);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //73 49 48 20 19 17
    n = create_new_list_node(17);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(19);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(20);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(48);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(49);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(73);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //18 17 16 15 15 94
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(15);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(19);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(16);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(17);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(18);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //86 84 83 82 81 80 89 98 96 95 94
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(95);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(96);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(98);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(89);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(80);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(81);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(82);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(83);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(84);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(86);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //66 76
    n = create_new_list_node(76);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(66);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //94
    n = create_new_list_node(94);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    temp = (transaction)malloc(sizeof(struct transaction));
    temp->data = NULL;
    temp->next = NULL;

    //98 64 27
    n = create_new_list_node(27);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(64);
    n->next = temp->data;
    temp->data = n;
    n = create_new_list_node(98);
    n->next = temp->data;
    temp->data = n;

    temp->next = t;
    t = temp;
    return t;
}

int pow_of_two(int i) {
    int ret = 1;
    ret = ret << 3;
    return ret;
}

void max_heapify(heap h, int index) {
    int left = 2*index+1;
    int right = 2*index+2;

    int largest = index;
    if (left < h->size && h->times[left] > h->times[largest])
        largest = left;
    if (right < h->size && h->times[right] > h->times[largest])
        largest = right;
    
    if (largest != index) {
        int temp_times = h->times[index];
        int temp_id = h->product[index];

        h->times[index] = h->times[largest];
        h->product[index] = h->product[largest];

        h->times[largest] = temp_times;
        h->product[largest] = temp_id;
        max_heapify(h, largest);
    }
}

heap representData(transaction t) {
    heap h = create_new_heap();

    while(t != NULL) {
        for(node n = t->data; n != NULL; n = n->next) 
            h->times[n->product_id - 1]++;
        t = t->next;
    }

    for(int i = h->depth + 1; i >= 0; i--) {
        int pow = 1;
        for(int j = i; j > 0; j--) {
            pow = pow*2;
        }
        for(int j = pow - 1; j < 2*pow; j++)
            max_heapify(h, j);
    }
    return h;
}

void print_heap(heap h) {
    for(int i = 0; i < h->size; i++) {
        printf("%d %d \n", h->product[i], h->times[i]);
    }
}

int getMax(heap h) {
    return h->product[0];
}

int main() {
    transaction store = createData();
    // print_transactions(store);
    heap data = representData(store);
    print_heap(data);
    int product_sold_most = getMax(data);
    printf("The product sold most by the store is: Product %d \n", product_sold_most);
    return 0;
}