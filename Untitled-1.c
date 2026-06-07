//inorder traversal

void inorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root ->right);
}

//postorder

void postorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);v
}