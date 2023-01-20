using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CRUDWithDataStructure
{
    internal class Student
    {
        public int rollNo { get; set; }
        public string name { get; set; }
        public string fatherName { get; set; }
        public string semester { get; set; }
        public string gender { get; set; }
        public bool check { get; set; }  
        public int rollNodelete { get; set; }
        public int rollNoupdate { get; set; }
        public string nameupdate { get; set; }
        public string fatherNameupdate { get; set; }
        public string semesterupdate { get; set; }
        public string genderupdate { get; set; }
        public Node head;

        public void AddRecord()
        {
            Node newNode = new Node();
            Node curr = head;
            newNode.rollNo = rollNo;
            newNode.name = name;
            newNode.fathername = fatherName;
            newNode.semester = semester;
            newNode.gender = gender;
            newNode.next = head;
            if(head==null)
            {
                newNode.prev = null;
                head = newNode;
                MessageBox.Show("Your data Submited");
            }
            else
            {
                while(curr!=null)
                {
                    curr = curr.next;
                }
                curr.next = newNode;
                newNode.prev = curr;
                MessageBox.Show("Your data Submited");
            }
            

        }
        ///
        public void deleteRecord()
        {
            if(check)
            {
                Node curr, temp;
                    curr= head;
               
                while (curr.next!=null)
                {
                    if(curr.rollNo==rollNodelete)
                    {
                        temp = curr;
                        temp.prev.next = temp.next;
                        temp.next.prev = temp.prev;
                        curr = temp.prev;
                        MessageBox.Show("Delete Record");
                    }
                    curr = curr.next;
                }
            }
            else
            {
                MessageBox.Show("Confirm");
            }
           
        }
        //void 
        public void showupdate()
        {
            Node curr;
            curr = head;
            while(curr!= null)
            {
                if(curr.rollNo==rollNoupdate)
                {
                    curr.name= nameupdate;
                     curr.fathername= fatherNameupdate;
                    curr.semester= semesterupdate;
                    curr.gender = genderupdate;
                    MessageBox.Show("Update data");
                }
                curr = curr.next;

            }
        }

        public void editUpdate()
        {

            Node curr;
            curr = head;
            while (curr != null)
            {
                if (curr.rollNo == rollNoupdate)
                {
                    nameupdate = curr.name;
                    fatherNameupdate = curr.fathername;
                    semesterupdate = curr.semester;
                    genderupdate = curr.gender;
                }
                curr = curr.next;
                

            }
        }
        ///Show Data
        public void ShowRecord(int rollNo,string a,string b,string c,string d)
        {
            Node curr;
            curr = head;
            while(curr!=null)
            {
                if(rollNo==curr.rollNo)
                {
                    a = curr.name;
                    a.Remove = true;

                    b = curr.fathername;
                    c = curr.semester;
                    d= curr.gender;
                }
                curr = curr.next;
            }
        }
    }
}
