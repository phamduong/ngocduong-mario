using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor_v10
{
   public class RECT
    {
      
        public float left, top, right, bottom;
        //khoi tao
        public RECT() 
        {
            left = top = right = bottom = -1;
        }
        public RECT(float _left, float _top, float _right, float _bottom)
        {
            left = _left;
            top = _top;
            right = _right;
            bottom = _bottom;
        }
        public void SetLeft(float _left)
        {
            left = _left;
        }
        public void SetTop(float _top)
        {
            top = _top;
        }
        public void SetRight(float _right)
        {
            right = _right;
        }
        public void SetBottom(float _bottom)
        {
            bottom = _bottom;
        }
        // get
        public float GetLeft()
        {
            return left;
        }
        public float GetRight()
        {
            return right;
        }
        public float GetTop()
        {
            return top;
        }
        public float GetBottom()
        {
            return bottom;
        }
    }
}
