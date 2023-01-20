class StudentNode
{
    public StudentData data;
    public StudentNode leftChild;
    public StudentNode rightChild;

    public StudentNode(StudentData data)
    {
        this.data = data;
        leftChild = null;
        rightChild = null;
    }
}

class StudentBinaryTree
{
    public StudentNode root;

    public StudentBinaryTree()
    {
        root = null;
    }

    // Insert a new node into the tree
    public void Insert(StudentData data)
    {
        StudentNode newNode = new StudentNode(data);

        if (root == null)
        {
            root = newNode;
        }
        else
        {
            StudentNode current = root;
            StudentNode parent;
            while (true)
            {
                parent = current;
                if (data.ID < current.data.ID)
                {
                    current = current.leftChild;
                    if (current == null)
                    {
                        parent.leftChild = newNode;
                        break;
                    }
                }
                else
                {
                    current = current.rightChild;
                    if (current == null)
                    {
                        parent.rightChild = newNode;
                        break;
                    }
                }
            }
        }
    }

    // Search for a node with a specific ID
    public StudentNode Search(int ID)
    {
        StudentNode current = root;
        while (current != null)
        {
            if (current.data.ID == ID)
            {
                return current;
            }
            else if (ID < current.data.ID)
            {
                current = current.leftChild;
            }
            else
            {
                current = current.rightChild;
            }
        }
        return null;
    }
}

class StudentData
{
    public int ID;
    public string name;
    public string email;
    public string phone;

    public StudentData(int ID, string name, string email, string phone)
    {
        this.ID = ID;
        this.name = name;
        this.email = email;
        this.phone = phone;
    }
}



