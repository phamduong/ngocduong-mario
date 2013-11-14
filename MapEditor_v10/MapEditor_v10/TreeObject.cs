using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace MapEditor_v10
{
    public class TreeObject
    {
        public RECT m_boundTreeObject;
        public int m_IdTreeObject;
        public QNode m_NodeRoot;
        float widthmap = 16000;


        //khoi tao not Root
        public TreeObject()
        {
            m_NodeRoot = new QNode(0, 0, widthmap, widthmap, 0);
            m_NodeRoot.ListTreeObjectInNode = m_NodeRoot.ListTreeObjectInGame;
        }
        public TreeObject(int _id, RECT _bound)
        {
            m_boundTreeObject = _bound;
            m_IdTreeObject = _id;
        }
        ~TreeObject()
        {
        }
        //
        public static bool Interset(RECT Object, RECT Node)
        {
            if (Object.GetRight() <= Node.GetLeft())
                return false;
            if (Object.GetLeft() >= Node.GetRight())
                return false;
            if (Object.GetTop() <= Node.GetBottom())
                return false;
            if (Object.GetBottom() >= Node.GetTop())
                return false;
            return true;
        }
        public static RECT Clip(RECT Object, RECT Node)
        {
            if (Interset(Object, Node) == true)
            {
                RECT rect = new RECT();
                if (Object.GetLeft() <= Node.GetLeft() && Object.GetRight() >= Node.GetLeft() && Object.GetRight() <= Node.GetRight())
                {
                    rect.left = Node.left;
                    rect.right = Object.right;

                }
                else if (Object.GetLeft() >= Node.GetLeft() && Object.GetLeft() <= Node.GetRight() && Object.GetRight() >= Node.GetLeft() && Object.GetRight() <= Node.GetRight())
                {
                    rect.left = Object.left;
                    rect.right = Object.right;
                }
                else if (Object.GetLeft() >= Node.GetLeft() && Object.GetLeft() <= Node.GetRight() && Object.GetRight() >= Node.GetRight())
                {
                    rect.left = Object.left;
                    rect.right = Node.right;
                }
                else // (Object.GetLeft() <= Node.GetLeft() && Object.GetRight() >= Object.GetRight())
                {
                    rect.left = Node.left;
                    rect.right = Node.right;
                }
                // xet theo truc y

                if (Object.GetBottom() <= Node.GetBottom() && Object.GetTop() >= Node.GetBottom() && Object.GetTop() <= Node.GetTop())
                {
                    rect.bottom = Node.bottom;
                    rect.top = Object.top;

                }
                else if (Object.GetBottom() >= Node.GetBottom() && Object.GetBottom() <= Node.GetTop() && Object.GetTop() >= Node.GetBottom() && Object.GetTop() <= Node.GetTop())
                {
                    rect.bottom = Object.bottom;
                    rect.top = Object.top;
                }
                else if (Object.GetBottom() >= Node.GetBottom() && Object.GetBottom() <= Node.GetTop() && Object.GetTop() >= Node.GetTop())
                {
                    rect.bottom = Object.bottom;
                    rect.top = Node.top;
                }
                else 
                {
                    rect.bottom = Node.bottom;
                    rect.top = Node.top;
                }

                return rect;
            }
            return null;
        }
        public static void Build(QNode Node)
        {
            //tinh kich thuoc node
            float widthnode = Node.GetBound().GetRight() - Node.GetBound().GetLeft();
            float heightnode = Node.GetBound().GetTop() - Node.GetBound().GetBottom();
            int IdTreeObject = -1;
            int[] check = new int[Node.GetTreeObjectInNode().Count + 1];
            //kiem tra xem node co co kich thuoc lon hon man hjnh mot xiu thj chja tjep
            if (widthnode > 1024 || heightnode > 1024)
            {
                // kiem tra xem co phan tu trong node ko
                if (Node.GetTreeObjectInNode().Count != 0)
                {
                    //tinh toa do giua theo 2 chieu
                    float MidleWidthNode = widthnode / 2 + Node.GetBound().GetLeft();
                    float MidleHeightNode = heightnode / 2 + Node.GetBound().GetBottom();
                    Node.NodeLeftTop = new QNode(Node.m_IdNode * 8 + 1, Node.GetBound().GetLeft(), Node.GetBound().GetTop(), MidleWidthNode, MidleHeightNode);
                    Node.NodeLeftBottom = new QNode(Node.m_IdNode * 8 + 3, Node.GetBound().GetLeft(), MidleHeightNode, MidleWidthNode, Node.GetBound().GetBottom());
                    Node.NodeRightTop = new QNode(Node.m_IdNode * 8 + 2, MidleWidthNode, Node.GetBound().GetTop(), Node.GetBound().GetRight(), MidleHeightNode);
                    Node.NodeRightBottom = new QNode(Node.m_IdNode * 8 + 4, MidleWidthNode, MidleHeightNode, Node.GetBound().GetRight(), Node.GetBound().GetBottom());
                    // xen tung doi tuong nam trog node Cha vao cac node con vua tao
                    for (int i = 0; i < Node.GetTreeObjectInNode().Count; i++)
                    {
                        IdTreeObject = Node.GetTreeObjectInNode()[i].m_IdTreeObject;

                        //xen cac node
                        RECT rect2 = Clip(Node.GetTreeObjectInNode()[i].m_boundTreeObject, Node.NodeLeftBottom.GetBound());
                        if (rect2 != null)
                        {
                            Node.NodeLeftBottom.AddTreeObjectInNode(new TreeObject(IdTreeObject, rect2));

                        }
                        RECT rect1 = Clip(Node.GetTreeObjectInNode()[i].m_boundTreeObject, Node.NodeLeftTop.GetBound());
                        if (rect1 != null)
                        {
                            Node.NodeLeftTop.AddTreeObjectInNode(new TreeObject(IdTreeObject, rect1));

                        }


                        RECT rect3 = Clip(Node.GetTreeObjectInNode()[i].m_boundTreeObject, Node.NodeRightBottom.GetBound());
                        if (rect3 != null)
                        {
                            Node.NodeRightBottom.AddTreeObjectInNode(new TreeObject(IdTreeObject, rect3));

                        }
                        RECT rect4 = Clip(Node.GetTreeObjectInNode()[i].m_boundTreeObject, Node.NodeRightTop.GetBound());
                        if (rect4 != null)
                        {
                            Node.NodeRightTop.AddTreeObjectInNode(new TreeObject(IdTreeObject, rect4));

                        }
                        //xoa doi tuong do o node cha di  

                    }
                    Node.RemoveTreeObjectInNode();
                    //
                    Build(Node.NodeLeftTop);
                    Build(Node.NodeLeftBottom);
                    Build(Node.NodeRightBottom);
                    Build(Node.NodeRightTop);

                }
            }

        }

        public static void Save(QNode node, StreamWriter sw)
        {

            if (node.NodeLeftTop != null)
            {
                String BoundNode = node.NodeLeftTop.GetBound().GetLeft().ToString() + " " + node.NodeLeftTop.GetBound().GetTop().ToString()
                    + " " + node.NodeLeftTop.GetBound().GetRight().ToString() + " " + node.NodeLeftTop.GetBound().GetBottom().ToString();
                String ListId = "";
                for (int i = 0; i < node.NodeLeftTop.GetTreeObjectInNode().Count; i++)
                {
                    ListId += " " + node.NodeLeftTop.GetTreeObjectInNode()[i].m_IdTreeObject.ToString();
                }

                sw.WriteLine(node.NodeLeftTop.m_IdNode + " " + BoundNode + ListId);
                Save(node.NodeLeftTop, sw);
            }
            if (node.NodeLeftBottom != null)
            {
                String BoundNode = node.NodeLeftBottom.GetBound().GetLeft().ToString() + " " + node.NodeLeftBottom.GetBound().GetTop().ToString()
                    + " " + node.NodeLeftBottom.GetBound().GetRight().ToString() + " " + node.NodeLeftBottom.GetBound().GetBottom().ToString();
                String ListId = "";
                for (int i = 0; i < node.NodeLeftBottom.GetTreeObjectInNode().Count; i++)
                {
                    ListId += " " + node.NodeLeftBottom.GetTreeObjectInNode()[i].m_IdTreeObject.ToString();
                }
                sw.WriteLine(node.NodeLeftBottom.m_IdNode + " " + BoundNode + ListId);
                Save(node.NodeLeftBottom, sw);
            }
            if (node.NodeRightTop != null)
            {
                String BoundNode = node.NodeRightTop.GetBound().GetLeft().ToString() + " " + node.NodeRightTop.GetBound().GetTop().ToString()
                    + " " + node.NodeRightTop.GetBound().GetRight().ToString() + " " + node.NodeRightTop.GetBound().GetBottom().ToString();
                String ListId = "";
                for (int i = 0; i < node.NodeRightTop.GetTreeObjectInNode().Count; i++)
                {
                    ListId += " " + node.NodeRightTop.GetTreeObjectInNode()[i].m_IdTreeObject.ToString();
                }
                sw.WriteLine(node.NodeRightTop.m_IdNode + " " + BoundNode + ListId);
                Save(node.NodeRightTop, sw);
            }
            if (node.NodeRightBottom != null)
            {
                String BoundNode = node.NodeRightBottom.GetBound().GetLeft().ToString() + " " + node.NodeRightBottom.GetBound().GetTop().ToString()
                    + " " + node.NodeRightBottom.GetBound().GetRight().ToString() + " " + node.NodeRightBottom.GetBound().GetBottom().ToString();
                String ListId = "";
                for (int i = 0; i < node.NodeRightBottom.GetTreeObjectInNode().Count; i++)
                {
                    ListId += " " + node.NodeRightBottom.GetTreeObjectInNode()[i].m_IdTreeObject.ToString();
                }
                sw.WriteLine(node.NodeRightBottom.m_IdNode + " " + BoundNode + ListId);
                Save(node.NodeRightBottom, sw);
            }

        }
    }

}
