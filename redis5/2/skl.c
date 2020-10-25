#include<stdlib.h>

typedef char *sds;
#define ZSKIPLIST_MAXLEVEL 64 /* Should be enough for 2^64 elements */
#define ZSKIPLIST_P 0.25      /* Skiplist P = 1/4 */

typedef struct zskiplistNode {
    sds ele;
    double score;
    struct zskiplistNode *backward;
    struct zskiplistLevel {
        struct zskiplistNode *forward;
        unsigned long span;
    } level[];
} zskiplistNode;

typedef struct zskiplist {
    struct zskiplistNode *header, *tail;
    unsigned long length;
    int level;
} zskiplist;

/* Create a skiplist node with the specified number of levels.
 * The SDS string 'ele' is referenced by the node after the call. */
zskiplistNode *zslCreateNode(int level, double score, sds ele) {
    zskiplistNode *zn =
        malloc(sizeof(*zn)+level*sizeof(struct zskiplistLevel));
    zn->score = score;
    zn->ele = ele;
    return zn;
}

int zslRandomLevel(void) {
    int level = 1;
    while ((random()&0xFFFF) < (ZSKIPLIST_P * 0xFFFF))
        level += 1;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
}

zskiplistNode *zslInsert(zskiplist *zsl, double score, sds ele) {
    int i;
    zskiplistNode* x = zsl->header;
    zskiplistNode* pre = NULL;
    int rank[ZSKIPLIST_MAXLEVEL];
    zskiplistNode* update[ZSKIPLIST_MAXLEVEL];
    for(i = zsl->level - 1; i >= 0; i--) {
        rank[i] = (i == zsl->level - 1) ? 0 : rank[i + 1];
        while(x->level[i].forward && x->level[i].forward->score < score) {
            rank[i] += x->level[i].span;
            x = x->level[i].forward;
        }
        update[i] = x;
    }
    int level = zslRandomLevel();
    x = zslCreateNode(level, score, ele);
    rank[0] + 1;
    for(i = 0; i < level; i++) {
        x->level[i].forward = update[i]->level[i].forward;
        update[i]->level[i].forward = x;
        x->level[i].span = update[i]->level[i].span - 1;
        update[i]->level[i].span = rank[0] + 1 - rank[i];
    }
}

int zslDelete(zskiplist *zsl, double score, sds ele, zskiplistNode **node) {
    
}