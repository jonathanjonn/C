#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define cls system("cls");

// Jonathan Andreanus - 2502016424

typedef struct node
{
    int id;
    char name[20];
    int jam, menit, detik;
    struct node *left, *right;
} node;

node *createnewnode(int id, char name[], int jam, int menit, int detik)
{
    node *newnode = (node *)malloc(sizeof(node *));
    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->jam = jam;
    newnode->menit = menit;
    newnode->detik = detik;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("NIM\t: %d\nNama\t: %s\nJam\t: %02d:%02d:%02d\n\n", root->id, root->name, root->jam, root->menit, root->detik);
        inorder(root->right);
    }
}

node *insert(node *root, int id, char name[], int jam, int menit, int detik)
{

    if (root == NULL)
    {
        return createnewnode(id, name, jam, menit, detik);
    }
    else if (id < root->id)
    {
        root->left = insert(root->left, id, name, jam, menit, detik);
    }
    else if (id > root->id)
    {
        root->right = insert(root->right, id, name, jam, menit, detik);
    }
    return root;
}

int search(node *root, int findid)
{
    int found;
    if (root != NULL)
    {
        search(root->left, findid);
        if (root->id == findid)
        {
            printf("\nNIM %d FOUND!\n", root->id);
            printf("Nama\t: %s\nMasuk pada pukul: %02d:%02d:%02d\n", root->name, root->jam, root->menit, root->detik);
            found++;
            return found;
        }
        search(root->right, findid);
    }
}

void menu()
{
    node *root = NULL;
    int select, nim, find, found;
    char name[20];

    time_t t;
    struct tm *Rtime;
    do
    {
        t = time(NULL);
        Rtime = localtime(&t);
        printf("=======Student attendance=======\n");
        printf("JAM : %02d:%02d:%02d\n", Rtime->tm_hour, Rtime->tm_min, Rtime->tm_sec);
        printf("1. Input student attendance\n");
        printf("2. Show student attendance\n");
        printf("3. Search student\n");
        printf("0. EXIT\n");
        printf("\nselect (1-3) : ");
        scanf("%d", &select);
        getchar();

        switch (select)
        {
        case 1:
            cls;
            printf("ID :");
            scanf("%d", &nim);
            getchar();
            printf("Name :");
            gets(name);
            root = insert(root, nim, name, Rtime->tm_hour, Rtime->tm_min, Rtime->tm_sec);
            char a;
            printf("Continue?(y/n)");
            scanf("%s", &a);
            if (a == 'y')
            {
                break;
                cls;
            }
            else if (a == 'n')
            {
                select = 0;
                break;
            }

        case 2:
            cls;
            inorder(root);
            char b;
            printf("Continue?(y/n)");
            scanf("%s", &b);
            if (b == 'y')
            {
                break;
                cls;
            }
            else if (b == 'n')
            {
                select = 0;
                break;
            }

        case 3:
            cls;
            printf("Masukkan nim yang dicari :");
            scanf("%d", &find);
            found = search(root, find);
            if (found == 0)
            {
                printf("The student was no present\n");
            }

            char c;
            printf("Continue?(y/n)");
            scanf("%s", &c);
            if (c == 'y')
            {
                break;
                cls;
            }
            else if (c == 'n')
            {
                select = 0;
                break;
            }

        case 0:
            break;

        default:
            break;
        }
    } while (select != 0);
}

int main()
{
    menu();
}