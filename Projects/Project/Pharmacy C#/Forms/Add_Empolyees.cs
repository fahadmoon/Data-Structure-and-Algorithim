using _1.Classes.Employee_Classes;
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
using System.Data.SqlClient;
using System.Data.SqlTypes;

namespace _1.Forms
{
    public partial class Add_Empolyees : Form
    {
        public string connectionString_EMS= @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=E:\Project\1\Storage\Employees.mdf;Integrated Security = True";
        private HashSet<int> usedNumbers;
        private Random random;
        public Add_Empolyees()
        {
            InitializeComponent();
        }
        //

        /// <RandomEmployeeID>
        /// This function creates for a random employees ID without duplicates
        private int EmployeeIDRandom()
        {


            usedNumbers = new HashSet<int>();
            random = new Random();
            int randomNumber;
            do
            {
                randomNumber = random.Next(5000, 9999);
            } while (usedNumbers.Contains(randomNumber));
            usedNumbers.Add(randomNumber);
            return randomNumber;
        }
        /// </RandomEmployeeID>


        private void gunaLabel2_Click(object sender, EventArgs e)
        {

        }

        private void Add_Empolyees_Load(object sender, EventArgs e)
        {

        }

        private void BTN_ESave_Click(object sender, EventArgs e)
        {
            //Create Object
            Employees employees = new Employees();

            int a = EmployeeIDRandom();
            
            //initialize for Textboxes
            string name_Employee = TextBox_EName.Text;
            string phone_Employee = TextBox_EPhoneNo.Text;
            int salary = Convert.ToInt32(TextBox_ESalary.Text);
            string joiningDate = this.TextBox_EJoinDate.Text;
            string password_Employee= TextBox_EPassword.Text;
            string Address_Employee = TextBox_Address.Text;
            

            if ( TextBox_EName.Text == "" || TextBox_EPhoneNo.Text == ""  || TextBox_EPassword.Text == "" || TextBox_Address.Text == "" || TextBox_EJoinDate.Text == "")
            {
                MessageBox.Show("Please Fill the Textbox");
            }
           
            else
            {
                SqlConnection connection = new SqlConnection(connectionString_EMS);
                try
                {
                    connection.Open();
                    string query = "INSERT INTO Employee(Employee_ID,Employee_Name,Phone,Joining_Date,Salary,Password_Employee,Address) VALUES (@em_ID,@Em_name,@phone,@jData,@salary,@Password,@address)";
                    SqlCommand sqlCommand = new SqlCommand(query, connection);
                    sqlCommand.Parameters.AddWithValue("@em_ID", a);
                    sqlCommand.Parameters.AddWithValue("@Em_name", name_Employee);
                    sqlCommand.Parameters.AddWithValue("@phone", phone_Employee);
                    sqlCommand.Parameters.AddWithValue("@jData", joiningDate);
                    sqlCommand.Parameters.AddWithValue("@salary", salary);
                    sqlCommand.Parameters.AddWithValue("@Password", password_Employee);
                    sqlCommand.Parameters.AddWithValue("@address", Address_Employee);
                    sqlCommand.ExecuteNonQuery();
                    //Show Employee ID in this Label
                    Employee_IdLabel.Text = Convert.ToString(a);
                    Employee_IdLabel.Visible= true;

                }

                catch (Exception w)
                {
                  MessageBox.Show(w.Message );
                }
                finally
                {
                    string sql = "SELECT* FROM Employee WHERE Employee_ID='"+a+"'";
                    SqlCommand cmd=new SqlCommand(sql, connection);
                    SqlDataReader reader = cmd.ExecuteReader();
                    while(reader.Read())
                    {
                        string id = reader["Employee_ID"].ToString();
                        string Name = reader["Employee_Name"].ToString();                       
                        string phone = reader["Phone"].ToString();                   
                        string joinDate = reader["Joining_Date"].ToString();                     
                        string s = reader["Salary"].ToString();
                        string password = reader["Password_Employee"].ToString() ;
                        string address = reader["Address"].ToString();

                        employees.InsertEmpolyee(new AddEmployee(Name, phone,Convert.ToInt32(id), joinDate, Convert.ToInt32(s), password, address));

                    }
                }
               
            }
            
        }

        private void TextBox_EJoinDate_ValueChanged(object sender, EventArgs e)
        {
            DateTime.Now.ToString("d/M/yyyy");
        }

        private void TextBox_EName_TextChanged(object sender, EventArgs e)
        {

        }

        private void TextBox_ESalary_TextChanged(object sender, EventArgs e)
        {

            try
            {
                if (Convert.ToInt32(TextBox_ESalary.Text) > 0)
                {

                }
                else
                {
                    MessageBox.Show("Enter the no greater than 0");

                }
            }
            catch (Exception w)
            {
                if (TextBox_ESalary.Text=="")
                {

                }
                else
                {
                    MessageBox.Show(w.Message);
                }
               
            }
        }

        private void gunaButton1_Click(object sender, EventArgs e)
        {

        }
    }
}
