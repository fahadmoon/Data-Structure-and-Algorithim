using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StudentBinaryTreeSearchTree
{
    public partial class Dispaly : Form
    {
        public Dispaly()
        {
            InitializeComponent();
        }

        private void Dispaly_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'studentsDataSet.Students' table. You can move, or remove it, as needed.
            this.studentsTableAdapter.Fill(this.studentsDataSet.Students);
            StudentBinaryTree studentBinaryTree = new StudentBinaryTree();
            string connectionString=@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = D:\BS Computer Science\3rd Semester\Data Structure & Algoritham\Projects\StudentBinaryTreeSearchTree\Students.mdf; Integrated Security = True";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string sql = "SELECT * FROM Students";
                SqlCommand command = new SqlCommand(sql, connection);
                SqlDataReader reader = command.ExecuteReader();

                while (reader.Read())
                {
                    int ID = reader.GetInt32(0);
                    string name = reader.GetString(1);
                    string email = reader.GetString(2);
                    string phone = reader.GetString(3);
                    StudentData data = new StudentData(ID, name, email, phone);
                    MessageBox.Show("Student found: ID = {0}, Name = {1}, Email = {2}, Phone = {3}");
                    studentBinaryTree.Insert(data);
                }
            }
            StudentNode result = studentBinaryTree.Search(123);
            if (result != null)
            {
                Console.WriteLine("Student found: ID = {0}, Name = {1}, Email = {2}, Phone = {3}",
                                  result.data.ID, result.data.name, result.data.email, result.data.phone);
            }
            else
            {
                Console.WriteLine("Student not found.");
            }

        }
    }
}
