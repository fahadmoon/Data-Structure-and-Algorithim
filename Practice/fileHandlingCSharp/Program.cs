public class StudentRecord
{
    public int StudentID { get; set; }
    public string Name { get; set; }
    public string Email { get; set; }
    public string Phone { get; set; }
    public DateTime EnrollmentDate { get; set; }
    public string Major { get; set; }
    public int Grade1 { get; set; }
    public int Grade2 { get; set; }
    public int Grade3 { get; set; }
}


public class LinkedListNode
{
    public StudentRecord Data { get; set; }
    public LinkedListNode Next { get; set; }
}


public class LinkedList
{
    public LinkedListNode Head { get; set; }
    public LinkedListNode Tail { get; set; }

    public void Add(StudentRecord data)
    {
        LinkedListNode newNode = new LinkedListNode
        {
            Data = data,
            Next = null
        };

        if (Head == null)
        {
            Head = newNode;
            Tail = newNode;
        }
        else
        {
            Tail.Next = newNode;
            Tail = newNode;
        }

        // Add the student record to the SQL database
        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();

            SqlCommand command = new SqlCommand("INSERT INTO Students (StudentID, Name, Email, Phone, EnrollmentDate, Major, Grade1, Grade2, Grade3) VALUES (@StudentID, @Name, @Email, @Phone, @EnrollmentDate, @Major, @Grade1, @Grade2, @Grade3)", connection);
            command.Parameters.AddWithValue("@StudentID", data.StudentID);
            command.Parameters.AddWithValue("@Name", data.Name);
            command.Parameters.AddWithValue("@Email", data.Email);
            command.Parameters.AddWithValue("@Phone", data.Phone);
            command.Parameters.AddWithValue("@EnrollmentDate", data.EnrollmentDate);
            command.Parameters.AddWithValue("@Major", data.Major);
            command.Parameters.AddWithValue("@Grade1", data.Grade1);
            command.Parameters.AddWithValue("@Grade2", data.Grade2);
            command.Parameters.AddWithValue("@Grade3", data.Grade3);
            command.ExecuteNonQuery();
        }
    }
    public void Delete(int studentID)
    {
        LinkedListNode current = Head;
        LinkedListNode previous = null;

        while (current != null)
        {
            if (current.Data.StudentID == studentID)
            {
                if (previous != null)
                {
                    previous.Next = current.Next;
                }
                else
                {
                    Head = current.Next;
                }

                // Delete the student record from the SQL database
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    SqlCommand command = new SqlCommand("DELETE FROM Students WHERE StudentID = @StudentID", connection);
                    command.Parameters.AddWithValue("@StudentID", studentID);
                    command.ExecuteNonQuery();
                }

                break;
            }

            previous = current;
            current = Head;
        }
        public StudentRecord Search(int studentID)
        {
            LinkedListNode current = Head;

            while (current != null)
            {
                if (current.Data.StudentID == studentID)
                {
                    return current.Data;
                }

                current = current.Next;
            }

            return null;
        }


    }
