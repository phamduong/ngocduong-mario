using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace MapEditor_v10
{
    public class PictureBoxObject : PictureBox
    {
        public Rectangle m_boundPicture;
        public PictureBoxObject()
        {
        }
        public PictureBoxObject(Image _image, int _left, int _top)
        {
            this.Image = _image;
            this.SizeMode = PictureBoxSizeMode.CenterImage;
            this.Height = _image.Height;
            this.Width = _image.Width;
            this.Left = _left;
            this.Top = _top;
            this.MouseDown += LeftMouseDown;
            this.MouseUp += LeftMouseUp;
            this.MouseMove += LeftMouseMove;
            this.BorderStyle = BorderStyle.Fixed3D;
            m_boundPicture = new Rectangle(_left, _top, _image.Width, _image.Height);// new RECT(_left, _top, _left + _image.Width, _top - _image.Height);// bound  trong mapbang 1/2 trong Game
            //top,bottom chua chuyen ve toa do game, ptbcontain - (top - image);
            if (MapEditor.ObjectSelect != null)
            {
                MapEditor.ObjectSelect.BorderStyle = BorderStyle.None;

            }
        }
        public PictureBoxObject(Image _image, int _left, int _top, Rectangle _boundPicture)
        {
            this.Image = _image;
            this.SizeMode = PictureBoxSizeMode.CenterImage;
            this.Height = _image.Height;
            this.Width = _image.Width;
            this.Left = _left;
            this.Top = _top;
            this.MouseDown += LeftMouseDown;
            this.MouseUp += LeftMouseUp;
            this.BorderStyle = BorderStyle.Fixed3D;
            m_boundPicture = _boundPicture;
            if (MapEditor.ObjectSelect != null)
            {
                MapEditor.ObjectSelect.BorderStyle = BorderStyle.None;

            }
        }
        public void LeftMouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                if (MapEditor.ObjectSelect != null)
                {
                    MapEditor.ObjectSelect.BorderStyle = BorderStyle.None;
                    //   MapEditor.ObjectSelect.IsSelect = false;
                }
                this.BorderStyle = BorderStyle.Fixed3D;
                // this.IsSelect = true;
                MapEditor.ObjectSelect = (PictureBoxObject)sender;
                MapEditor.CheckDraw = false;

            }


        }
        public void LeftMouseUp(object sender, MouseEventArgs e)
        {

        }
        public void LeftMouseMove(object sender, MouseEventArgs e)
        {
           
        }
    }
}
