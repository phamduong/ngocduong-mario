using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor_v10
{
    public class QNode
    {
        public int m_IdNode;// id node
        public RECT m_boundNode;//hcn bao not
        public List<TreeObject> ListTreeObjectInGame = new List<TreeObject>();//danh sach Tree Object
        public QNode NodeLeftTop, NodeLeftBottom, NodeRightTop, NodeRightBottom;
        public List<TreeObject> ListTreeObjectInNode = new List<TreeObject>();
        public QNode()
        {
        }
        public QNode(int _idnode, float _left, float _top, float _right, float _bottom)
        {
            m_IdNode = _idnode;
            m_boundNode = new RECT(_left, _top, _right, _bottom);
        }
        public QNode(int _idNode, RECT _rect)
        {
            m_IdNode = _idNode;
            m_boundNode = _rect;
        }
        ~QNode()
        {
        }
        public void AddTreeObjectInNode(TreeObject Tobjet)
        {
            ListTreeObjectInNode.Add(Tobjet);
        }
        public List<TreeObject> GetTreeObjectInNode()
        {

            return ListTreeObjectInNode;

        }

        public void RemoveTreeObjectInNode()
        {
            ListTreeObjectInNode.Clear();
        }
        public RECT GetBound()
        {
            return m_boundNode;
        }


    }
}
