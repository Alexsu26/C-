#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 256 + 10;
bool failed;
struct Node
{
    bool have_value;
    int value;
    Node *left, *right;
    Node() : have_value(false), left(NULL), right(NULL) {}
};
Node *root;

Node *new_node()
{
    return new Node();
}

void remove_tree(Node *u)
{
    if (u == NULL)
        return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

void add_node(int value, char *s)
{
    Node *u = root;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'L')
        {
            if (u->left == NULL)
                u->left = new_node();
            u = u->left;
        }
        if (s[i] == 'R')
        {
            if (u->right == NULL)
                u->right = new_node();
            u = u->right;
        }
    }
    if (u->have_value)
        failed = true;
    u->value = value;
    u->have_value = true; //做标记
    return;
}
bool read_input()
{
    char s[maxn];
    int value;
    failed = false;
    remove_tree(root);
    root = new_node();
    for (;;)
    {
        if (scanf("%s", s) != 1)
            return false;
        if (!strcmp(s, "()"))
            break;
        sscanf(&s[1], "%d", &value);
        add_node(value, strchr(s, ',') + 1);
    }
    return true;
}

bool bfs(vector<int> &q)
{
    queue<Node *> nq;
    nq.push(root);
    q.clear();
    while (!nq.empty())
    {
        Node *u = nq.front();
        nq.pop();
        if (!u->have_value)
            return false;
        q.push_back(u->value);
        if (u->left != NULL)
            nq.push(u->left);
        if (u->right != NULL)
            nq.push(u->right);
    }
    return true;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    vector<int> ans;
    while (read_input())
    {
        if (!bfs(ans))
            failed = true;
        if (failed)
            printf("not complete\n");
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                if (i != 0)
                    printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}