#include <sys/queue.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    STAILQ_HEAD(stailhead, entry)
    head = STAILQ_HEAD_INITIALIZER(head);
    struct stailhead *headp; /* Singly-linked tail queue head. */
    struct entry
    {
        STAILQ_ENTRY(entry)
        entries;
        char *s; /* Tail queue. */
    } * n1, *n2, *n3, *np;

    STAILQ_INIT(&head); /* Initialize the queue. */

    n1 = malloc(sizeof(struct entry)); /* Insert at the head. */
    STAILQ_INSERT_HEAD(&head, n1, entries);

    n1 = malloc(sizeof(struct entry)); /* Insert at the tail. */
    STAILQ_INSERT_TAIL(&head, n1, entries);

    n2 = malloc(sizeof(struct entry)); /* Insert after. */
    n1->s = (char *)malloc(sizeof(char) * 10);
    strcpy(n1->s, "Hello");
    //n2->s = (char *) malloc (sizeof(char)*10);
    //strcpy(n2->s,"Hello");
    STAILQ_INSERT_AFTER(&head, n1, n2, entries);
    /* Deletion. */
    STAILQ_REMOVE(&head, n2, entry, entries);
    free(n2);
    /* Deletion from the head. */
    n3 = STAILQ_FIRST(&head);
    STAILQ_REMOVE_HEAD(&head, entries);
    free(n3);
    /* Forward traversal. */
    STAILQ_FOREACH(np, &head, entries)
    {
        printf("%s\n", np->s);
    }
    //np->...
    /* TailQ Deletion. */
    while (!STAILQ_EMPTY(&head))
    {
        n1 = STAILQ_FIRST(&head);
        STAILQ_REMOVE_HEAD(&head, entries);
        free(n1);
    }
    /* Faster TailQ Deletion. */
    n1 = STAILQ_FIRST(&head);
    while (n1 != NULL)
    {
        n2 = STAILQ_NEXT(n1, entries);
        free(n1);
        n1 = n2;
    }
    STAILQ_INIT(&head);

    return 0;
}