using _1.Classes.Employee_Classes;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1.Forms
{
    public partial class UpdateEmployeeRecord : Form
    {
        public string connectionString_EMS = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=E:\Project\1\Storage\Employees.mdf;Integrated Security = True";

        public UpdateEmployeeRecord()
        {
            InitializeComponent();
        }

        private void BTN_ESave_Click(object sender, EventArgs e)
        {

        }

        private void gunaButton1_Click(object sender, EventArgs e)
        {
            string id, Name, phone, s, password, address;
            Employees employees = new Employees();

            AddEmployee addEmployee;
            //addEmployee = employees.SearchEmployee(Convert.ToInt32(TextBox_EmployeeID.Text));
            SqlConnection connection = new SqlConnection(connectionString_EMS);

            try
            {
                connection.Open();
                string sql = "SELECT* FROM Employee WHERE Employee_ID='" + TextBox_EmployeeID.Text + "'";
                SqlCommand cmd = new SqlCommand(sql, connection);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                     id = reader["Employee_ID"].ToString();
                     Name = reader["Employee_Name"].ToString();
                     phone = reader["Phone"].ToString();
                     s = reader["Salary"].ToString();
                     password = reader["Password_Employee"].ToString();
                    address = reader["Address"].ToString();
                    TextBox_EName.Text = Name;
                    TextBox_EPhoneNo.Text = phone;
                    TextBox_ESalary.Text = s;
                    TextBox_EPassword.Text = password;
                    TextBoxAddress.Text = address;
                    addEmployee = employees.SearchEmployee(Convert.ToInt32(id));
                }


            }
            catch(Exception w)
            {
                MessageBox.Show(w.Message);
            }
            finally
            {
                connection.Close();
            }

                /*
                            if(addEmployee==null)
                            {
                                MessageBox.Show("Not Found");
                            }
                            else
                            {
                                MessageBox.Show(addEmployee.nameEmployee);

                            }*/

            
            }
    }
}
