using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace MapEditor_v10
{


    public partial class MapEditor : Form
    {

        List<Image> ListImage = new List<Image>();// list chua tat ca cac hinh
        List<int> WidthMap = new List<int>();// 2 bjen chua to do x cac doi tuong,tim ra chieu dai va chieu rong map
        List<int> HeightMap = new List<int>();
        Image m_image;//hinh lay duoc khi kich vao button
        public static PictureBoxObject ObjectSelect;

        public static int m_widthMap;
        public static int m_heightMap;
        //dùng để load , save file
        private Stream _streamFile;
        SaveFileDialog saveFile = new SaveFileDialog();
        OpenFileDialog loadFile = new OpenFileDialog();
        TreeObject TreeObjectGame = new TreeObject();
        //  ve hinh chu nhat 
        public static bool CheckDraw = false;
        Point startPos;
        Point currentPos;
        bool drawing;
        List<Rectangle> rectangles = new List<Rectangle>();
        //ve tree len man hjnh
        Graphics gr;//ve len man hinh
        int WidthTreeRootGr = 0;//dung lay kich thuoc node goc de ve len man hjnh
        // kthcn
        private Rectangle getRectangle()
        {
            return new Rectangle(
                Math.Min(startPos.X, currentPos.X),
                Math.Min(startPos.Y, currentPos.Y),
                Math.Abs(startPos.X - currentPos.X),
                Math.Abs(startPos.Y - currentPos.Y));
        }
        //
        public MapEditor()
        {
            InitializeComponent();

        }
        private void SaveDataToFile()
        {
            int Id = 0;// id cua doi tuong khi luu vao file Map
            foreach (PictureBoxObject control in ptbContain.Controls)
            {
                WidthMap.Add(2 * control.Location.X + control.Image.Width);
                HeightMap.Add(2 * ptbContain.Height - 2 * control.Location.Y - control.Image.Height);
            }
            WidthMap.Sort();
            HeightMap.Sort();

            using (StreamWriter w = new StreamWriter(_streamFile))
            {
                m_heightMap = Math.Max(800, HeightMap[HeightMap.Count - 1]);
                m_widthMap = Math.Max(800, WidthMap[HeightMap.Count - 1]);
                w.WriteLine(m_widthMap.ToString() + " " + m_heightMap.ToString());
                foreach (PictureBoxObject control in ptbContain.Controls)
                {
                    int x = 2 * control.Location.X + control.Image.Width;
                    int y = 2 * ptbContain.Height - (2 * control.Location.Y + control.Image.Height);
                    //(2 * ptbContain.Height - y - control.Image.Height)/ 2
                    RECT rect = new RECT();
                    rect.left = 2 * control.m_boundPicture.Left;// 2 * control.Location.X;
                    rect.right = rect.left + 2 * control.m_boundPicture.Width;
                    rect.top = 2 * (ptbContain.Height - control.m_boundPicture.Top);//2 * (ptbContain.Height - control.Location.Y);
                    rect.bottom = rect.top - 2 * control.m_boundPicture.Height;
                    if (control.Image == ListImage[0])
                    {
                        w.WriteLine(Id.ToString() + " " + "CLOUD " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[1])
                    {
                        w.WriteLine(Id.ToString() + " " + "GRASS " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[2])
                    {
                        w.WriteLine(Id.ToString() + " " + "BIGTREE " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[3])
                    {
                        w.WriteLine(Id.ToString() + " " + "SMALLTREE " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[4])
                    {
                        w.WriteLine(Id.ToString() + " " + "BIGPIPE " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[5])
                    {
                        w.WriteLine(Id.ToString() + " " + "MEDIUMPIPE " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[6])
                    {
                        w.WriteLine(Id.ToString() + " " + "SMALLPIPE " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[7])
                    {
                        w.WriteLine(Id.ToString() + " " + "FENCE " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[8])
                    {
                        w.WriteLine(Id.ToString() + " " + "MOUNTAIN " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[9])
                    {
                        w.WriteLine(Id.ToString() + " " + "HOUSE " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[10])
                    {
                        w.WriteLine(Id.ToString() + " " + "BRICK " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[11])
                    {
                        w.WriteLine(Id.ToString() + " " + "LAND " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[12])
                    {
                        w.WriteLine(Id.ToString() + " " + "COINQUESTION " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[13])
                    {
                        w.WriteLine(Id.ToString() + " " + "COIN " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[14])
                    {
                        w.WriteLine(Id.ToString() + " " + "FLOWER " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[15])
                    {
                        w.WriteLine(Id.ToString() + " " + "STAR " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[16])
                    {
                        w.WriteLine(Id.ToString() + " " + "MUSHROOMBIG " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[17])
                    {
                        w.WriteLine(Id.ToString() + " " + "MUSHROOMLIFE " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[18])
                    {
                        w.WriteLine(Id.ToString() + " " + "MUSHROOM " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[19])
                    {
                        w.WriteLine(Id.ToString() + " " + "TURTLE " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[20])
                    {
                        w.WriteLine(Id.ToString() + " " + "BOSS " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                    else if (control.Image == ListImage[21])
                    {
                        w.WriteLine(Id.ToString() + " " + "FLAG " + x.ToString() + " " + y.ToString());
                        TreeObjectGame.m_NodeRoot.ListTreeObjectInNode.Add(new TreeObject(Id, rect));
                        Id++;
                    }
                }
                w.WriteLine("<End>");
            }
        }
        private void LoadDataToFile()
        {
            string NameObject;
            int x, y;
            if (loadFile.ShowDialog() == DialogResult.OK)
            {
                ptbContain.Controls.Clear();
                string filePath = loadFile.FileName;
                StreamReader sr = File.OpenText(filePath);
                string line = null;
                line = sr.ReadLine();
                while ((line = sr.ReadLine()) != null)
                {
                    if (line.Trim().CompareTo("<End>") == 0)
                    {
                        break;
                    }
                    string[] result = line.Split(' ');
                    NameObject = result[1].Trim();
                    x = int.Parse(result[2].ToString());
                    y = int.Parse(result[3].ToString());
                    //load vao nao
                    //(2 * ptbContain.Height - y - control.Image.Height)/ 2
                    if (NameObject.CompareTo("CLOUD") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[0], (x - ListImage[0].Width) / 2, (2 * ptbContain.Height - (y + ListImage[0].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("GRASS") == 0)
                    {

                        PictureBoxObject ptb = new PictureBoxObject(ListImage[1], (x - ListImage[1].Width) / 2, (2 * ptbContain.Height - (y + ListImage[1].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("BIGTREE") == 0)
                    {

                        PictureBoxObject ptb = new PictureBoxObject(ListImage[2], (x - ListImage[2].Width) / 2, (2 * ptbContain.Height - (y + ListImage[2].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("SMALLTREE") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[3], (x - ListImage[3].Width) / 2, (2 * ptbContain.Height - (y + ListImage[3].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("BIGPIPE") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[4], (x - ListImage[4].Width) / 2, (2 * ptbContain.Height - (y + ListImage[4].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("MEDIUMPIPE") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[5], (x - ListImage[5].Width) / 2, (2 * ptbContain.Height - (y + ListImage[5].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("SMALLPIPE") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[6], (x - ListImage[6].Width) / 2, (2 * ptbContain.Height - (y + ListImage[6].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("FENCE") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[7], (x - ListImage[7].Width) / 2, (2 * ptbContain.Height - (y + ListImage[7].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("MOUNTAIN") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[8], (x - ListImage[8].Width) / 2, (2 * ptbContain.Height - (y + ListImage[8].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("HOUSE") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[9], (x - ListImage[9].Width) / 2, (2 * ptbContain.Height - (y + ListImage[9].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("BRICK") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[10], (x - ListImage[10].Width) / 2, (2 * ptbContain.Height - (y + ListImage[10].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("LAND") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[11], (x - ListImage[11].Width) / 2, (2 * ptbContain.Height - (y + ListImage[11].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("COINQUESTION") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[12], (x - ListImage[12].Width) / 2, (2 * ptbContain.Height - (y + ListImage[12].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("COIN") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[13], (x - ListImage[13].Width) / 2, (2 * ptbContain.Height - (y + ListImage[13].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);
                        ptbContain.Invalidate();
                    }
                    else if (NameObject.CompareTo("FLOWER") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[14], (x - ListImage[14].Width) / 2, (2 * ptbContain.Height - (y + ListImage[14].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("STAR") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[15], (x - ListImage[15].Width) / 2, (2 * ptbContain.Height - (y + ListImage[15].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("MUSHROOMBIG") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[16], (x - ListImage[16].Width) / 2, (2 * ptbContain.Height - (y + ListImage[16].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("MUSHROOMLIFE") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[17], (x - ListImage[17].Width) / 2, (2 * ptbContain.Height - (y + ListImage[17].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("MUSHROOM") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[18], (x - ListImage[18].Width) / 2, (2 * ptbContain.Height - (y + ListImage[18].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("TURTLE") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[19], (x - ListImage[19].Width) / 2, (2 * ptbContain.Height - (y + ListImage[19].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("BOSS") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[20], (x - ListImage[20].Width) / 2, (2 * ptbContain.Height - (y + ListImage[20].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }
                    else if (NameObject.CompareTo("FLAG") == 0)
                    {
                        PictureBoxObject ptb = new PictureBoxObject(ListImage[21], (x - ListImage[21].Width) / 2, (2 * ptbContain.Height - (y + ListImage[21].Height)) / 2);
                        ptb.BorderStyle = BorderStyle.None;
                        ptbContain.Controls.Add(ptb);

                    }

                }
            }

        }

        public void SaveTree(StreamWriter sw)
        {
            int WidthTreeRoot = 0;
            for (int i = 1; i <= 20; i++)
            {

                if (Math.Pow(2, i) >= Math.Max(m_heightMap, m_widthMap))
                {
                    WidthTreeRoot = (int)Math.Pow(2, i);
                    break;
                }
            }
            TreeObjectGame.m_NodeRoot.m_boundNode.right = (float)WidthTreeRoot;
            TreeObjectGame.m_NodeRoot.m_boundNode.top = (float)WidthTreeRoot;
            sw.WriteLine("0 0 " + WidthTreeRoot.ToString() + " " + WidthTreeRoot.ToString() + " 0");//
            TreeObject.Build(TreeObjectGame.m_NodeRoot);
            TreeObject.Save(TreeObjectGame.m_NodeRoot, sw);
            sw.WriteLine("<End>");
            sw.Close();
        }

        private void saveToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            if (saveFile.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    // luu map 
                    _streamFile = File.Open(saveFile.FileName.ToString() + ".txt", FileMode.OpenOrCreate, FileAccess.Write);
                    SaveDataToFile();
                    _streamFile.Close();
                    //luu tree
                    Stream fs = File.Open(saveFile.FileName.ToString() + "Tree.txt", FileMode.OpenOrCreate, FileAccess.Write);
                    StreamWriter sw = new StreamWriter(fs);
                    SaveTree(sw);
                    fs.Close();
                    MessageBox.Show("Successfull!", "Save");
                }
                catch
                {
                }
            }


        }

        private void newToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            ptbContain.Controls.Clear();
        }

        private void ptbContain_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.X >= ptbContain.Width - 300)
            {
                int x = ptbContain.Width + 300;
                this.ptbContain.Size = new System.Drawing.Size(x, 2000);
            }

            if (e.Button == MouseButtons.Left)
            {

                if (CheckDraw == true)
                {
                    currentPos = startPos = e.Location;
                    drawing = true;
                }
            }
            else
            {
                for (int i = 0; i < rectangles.Count; i++)
                {
                    if (e.X >= rectangles[i].Left && e.X <= rectangles[i].Right && e.Y <= rectangles[i].Bottom && e.Y >= rectangles[i].Top)
                    {
                        rectangles.RemoveAt(i);
                        ptbContain.Invalidate();
                    }
                }
            }

            if (m_image != null && e.Button == MouseButtons.Left)
            {
                PictureBoxObject ptb = new PictureBoxObject(m_image, e.X - m_image.Width / 2, e.Y - m_image.Height / 2);
                ptbContain.Controls.Add(ptb);
                ObjectSelect = ptb;
            }

            if (e.Button == MouseButtons.Right && ObjectSelect != null)
            {
                m_image = null;
                ObjectSelect.BorderStyle = BorderStyle.None;
                ObjectSelect = null;

            }

        }

        public void DeleteObject(PictureBoxObject ptb)
        {
            ptbContain.Controls.Remove(ObjectSelect);
        }

        private void MapEditor_Load(object sender, EventArgs e)
        {
            Image _image = Image.FromFile(Application.StartupPath + "\\Resource\\cloud.png"); //0
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\Grass.png"); //1
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\big_tree.png");//2
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\small_tree.png");//3
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\big_pipe.png");//4
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\medium_pipe.png");//5
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\small_pipe.png");//6
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\fence.png");//7
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\moutain.png");//8
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\house.png");//9
            //
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\Brick.png");// 10
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\Brick2.png");// 11
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\CoinQuestion.png");//12
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\coin.png");//13
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\Flower.png");//14
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\star.png");//15
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\mushroombig.png");//16
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\mushroomlife.png");//17
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\mushroom.png");//18
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\turtle.png");//19
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\Boss.png");//20
            ListImage.Add(_image);
            _image = Image.FromFile(Application.StartupPath + "\\Resource\\cotco.png");//21
            ListImage.Add(_image);



        }

        private void btnCloud_Click(object sender, EventArgs e)
        {
            CheckDraw = false;
            m_image = ListImage[0];
        }
        private void btnGrass_Click(object sender, EventArgs e)
        {
            CheckDraw = false;
            m_image = ListImage[1];
        }

        private void btnBigtree_Click(object sender, EventArgs e)
        {
            CheckDraw = false;
            m_image = ListImage[2];
        }

        private void btnSmalltree_Click(object sender, EventArgs e)
        {
            CheckDraw = false;
            m_image = ListImage[3];
        }

        private void btnBigpipe_Click(object sender, EventArgs e)
        {
            m_image = ListImage[4];
            CheckDraw = false;
        }

        private void btnMediumPipe_Click(object sender, EventArgs e)
        {
            m_image = ListImage[5];
            CheckDraw = false;
        }

        private void btnSmallPipe_Click(object sender, EventArgs e)
        {
            m_image = ListImage[6];
            CheckDraw = false;
        }

        private void btnFence_Click(object sender, EventArgs e)
        {
            m_image = ListImage[7];
            CheckDraw = false;
        }

        private void btnMountain_Click(object sender, EventArgs e)
        {
            m_image = ListImage[8];
            CheckDraw = false;
        }

        private void btnHouse_Click(object sender, EventArgs e)
        {
            m_image = ListImage[9];
            CheckDraw = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            m_image = ListImage[10];
            CheckDraw = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            m_image = ListImage[11];
            CheckDraw = false;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            m_image = ListImage[12];
            CheckDraw = false;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            m_image = ListImage[13];
            CheckDraw = false;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            m_image = ListImage[14];
            CheckDraw = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            m_image = ListImage[15];
            CheckDraw = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            m_image = ListImage[16];
            CheckDraw = false;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            m_image = ListImage[17];
            CheckDraw = false;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            m_image = ListImage[18];
            CheckDraw = false;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            m_image = ListImage[19];
            CheckDraw = false;
        }
        private void btnBoss_Click(object sender, EventArgs e)
        {
            m_image = ListImage[20];
            CheckDraw = false;
        }
        private void btnCotCo_Click(object sender, EventArgs e)
        {
            m_image = ListImage[21];
            CheckDraw = false;
        }
        private void ptbContain_Click(object sender, EventArgs e)
        {

        }

        private void ptbContain_MouseUp(object sender, MouseEventArgs e)
        {
            if (CheckDraw == true)
            {
                try
                {
                    if (drawing)
                    {
                        drawing = false;
                        var rc = getRectangle();
                        if (rc.Width > 0 && rc.Height > 0)
                            rectangles.Add(rc);
                        ObjectSelect.m_boundPicture = rc;//set lai cai bound  cho  Doi tuong can ve

                    }
                }
                catch
                {
                }
            }
        }

        private void TabBackGround_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                ptbContain.Controls.Remove(ObjectSelect);

            }
            if (e.KeyCode == Keys.D)
            {
                int x = MapEditor.ObjectSelect.Location.X;
                x += 1;
                MapEditor.ObjectSelect.Left = x;
                ptbContain.Invalidate();

            }
            if (e.KeyCode == Keys.A)
            {
                int x = MapEditor.ObjectSelect.Location.X;
                x -= 1;
                MapEditor.ObjectSelect.Left = x;
                ptbContain.Invalidate();

            }
            if (e.KeyCode == Keys.S)
            {
                int y = MapEditor.ObjectSelect.Location.Y;
                y += 1;
                MapEditor.ObjectSelect.Top = y;
                ptbContain.Invalidate();

            }
            if (e.KeyCode == Keys.W)
            {
                int y = MapEditor.ObjectSelect.Location.Y;
                y -= 1;
                MapEditor.ObjectSelect.Top = y;
                ptbContain.Invalidate();
            }


        }

        private void ptbContain_MouseMove(object sender, MouseEventArgs e)
        {
            if (CheckDraw == true)
            {
                currentPos = e.Location;
                if (drawing)
                {
                    ptbContain.Invalidate();
                }
            }
            else
            {
                if (e.Button == MouseButtons.Left && MapEditor.ObjectSelect != null)
                {
                    int movex = e.X - MapEditor.ObjectSelect.Image.Width / 2;
                    int movey = e.Y - MapEditor.ObjectSelect.Image.Height / 2;
                    MapEditor.ObjectSelect.Left = movex;
                    MapEditor.ObjectSelect.Top = movey;
                    this.Invalidate();
                }
            }
        }

        private void loadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LoadDataToFile();
        }

        private void DrawRect_Click(object sender, EventArgs e)
        {
            CheckDraw = true;
            m_image = null;
        }

        private void ptbContain_Paint(object sender, PaintEventArgs e)
        {
            if (WidthTreeRootGr != 0)
            {
                DrawTree(e.Graphics, new RECT(0, WidthTreeRootGr, WidthTreeRootGr, 0));
               
            }


            if (rectangles.Count > 0)
            {
                e.Graphics.DrawRectangles(Pens.Black, rectangles.ToArray());
            }
            if (drawing)
                e.Graphics.DrawRectangle(Pens.Red, getRectangle());
        }

        private void DrawRect_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                ptbContain.Controls.Remove(ObjectSelect);

            }
            if (e.KeyCode == Keys.D)
            {
                int x = MapEditor.ObjectSelect.Location.X;
                x += 1;
                MapEditor.ObjectSelect.Left = x;
                ptbContain.Invalidate();

            }
            if (e.KeyCode == Keys.A)
            {
                int x = MapEditor.ObjectSelect.Location.X;
                x -= 1;
                MapEditor.ObjectSelect.Left = x;
                ptbContain.Invalidate();

            }
            if (e.KeyCode == Keys.S)
            {
                int y = MapEditor.ObjectSelect.Location.Y;
                y += 1;
                MapEditor.ObjectSelect.Top = y;
                ptbContain.Invalidate();

            }
            if (e.KeyCode == Keys.W)
            {
                int y = MapEditor.ObjectSelect.Location.Y;
                y -= 1;
                MapEditor.ObjectSelect.Top = y;
                ptbContain.Invalidate();
            }
        }

        private void button11_Click(object sender, EventArgs e)
        {
            try
            {
                int m_wid, m_hei;
                List<int> wid = new List<int>();
                List<int> hei = new List<int>();
                foreach (PictureBoxObject control in ptbContain.Controls)
                {
                    wid.Add(2 * control.Location.X + control.Image.Width);
                    hei.Add(2 * ptbContain.Height - 2 * control.Location.Y - control.Image.Height);
                }
                wid.Sort();
                hei.Sort();
                m_wid = Math.Max(800, wid[wid.Count - 1]);
                m_hei = Math.Max(800, hei[hei.Count - 1]);
                for (int i = 1; i <= 20; i++)
                {

                    if (Math.Pow(2, i) >= Math.Max(m_wid, m_hei))
                    {
                        WidthTreeRootGr = (int)Math.Pow(2, i);
                        WidthTreeRootGr = WidthTreeRootGr / 2;
                        break;
                    }
                }
            }
            catch (Exception)
            {
                MessageBox.Show("Chưa Có Đối Tượng nào cả !");

            }



        }
        private void DrawTree(Graphics grp, RECT rect)
        {
            float width = rect.right - rect.left;
            float height = rect.top - rect.bottom;
            if (width > 512)
            {
                float MidleWidtd = width / 2 + rect.left;
                float Midleheight = height / 2 + rect.bottom;
                try
                {
                    //ve cac dong ke mau do
                    grp.DrawLine(Pens.Red, MidleWidtd, rect.top, MidleWidtd, rect.bottom);
                    grp.DrawLine(Pens.Red, rect.left, Midleheight, rect.right, Midleheight);
                    //de qui lai nao
                    DrawTree(grp, new RECT(rect.left, rect.top, MidleWidtd, Midleheight));
                    DrawTree(grp, new RECT(rect.left, Midleheight, MidleWidtd, rect.bottom));
                    DrawTree(grp, new RECT(MidleWidtd, rect.top, rect.right, Midleheight));
                    DrawTree(grp, new RECT(MidleWidtd, Midleheight, rect.right, rect.bottom));
                }
                catch (Exception e)
                {
                    MessageBox.Show("Loi roi");
                }
            }



        }

        private void button11_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                ptbContain.Controls.Remove(ObjectSelect);

            }
            if (e.KeyCode == Keys.D)
            {
                int x = MapEditor.ObjectSelect.Location.X;
                x += 1;
                MapEditor.ObjectSelect.Left = x;
                ptbContain.Invalidate();

            }
            if (e.KeyCode == Keys.A)
            {
                int x = MapEditor.ObjectSelect.Location.X;
                x -= 1;
                MapEditor.ObjectSelect.Left = x;
                ptbContain.Invalidate();

            }
            if (e.KeyCode == Keys.S)
            {
                int y = MapEditor.ObjectSelect.Location.Y;
                y += 1;
                MapEditor.ObjectSelect.Top = y;
                ptbContain.Invalidate();

            }
            if (e.KeyCode == Keys.W)
            {
                int y = MapEditor.ObjectSelect.Location.Y;
                y -= 1;
                MapEditor.ObjectSelect.Top = y;
                ptbContain.Invalidate();
            }
        }







    }



}
