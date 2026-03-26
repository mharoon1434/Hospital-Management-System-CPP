<h1>🏥 Hospital Management System (C++)</h1>

<p>
A console-based Hospital Management System developed in C++ using Object-Oriented Programming (OOP) concepts and file handling.
This project simulates real-world hospital operations such as managing patients, doctors, nurses, admissions, billing, and admin login.
</p>

<hr>

<h2>🚀 Features</h2>

<h3>👤 Admin</h3>
<ul>
  <li>Secure login system</li>
  <li>View staff information (Doctors, Nurses, Admins)</li>
</ul>

<h3>🧑‍⚕️ Doctor Management</h3>
<ul>
  <li>View doctor details</li>
  <li>Search doctors by availability (day-wise)</li>
  <li>Assign doctor to patients</li>
</ul>

<h3>👩‍⚕️ Nurse Management</h3>
<ul>
  <li>View nurse details</li>
  <li>Assign nurse to admitted patients</li>
</ul>

<h3>🧍 Patient Management</h3>
<ul>
  <li>Add new patients</li>
  <li>Assign doctors</li>
  <li>Store patient records using file handling</li>
</ul>

<h3>🏥 Admission System</h3>
<ul>
  <li>Admit patients (new or existing)</li>
  <li>Assign rooms and nurses</li>
  <li>Track admission & discharge dates</li>
  <li>Calculate hospital fees</li>
</ul>

<h3>💰 Billing System</h3>
<ul>
  <li>Track paid/unpaid patients</li>
  <li>Process payments</li>
  <li>Different fee calculation for normal and admitted patients</li>
</ul>

<h3>🚪 Discharge System</h3>
<ul>
  <li>Discharge patients</li>
  <li>Ensure payment before discharge</li>
  <li>Update records automatically</li>
</ul>

<hr>

<h2>📂 File Handling</h2>
<ul>
  <li>Doctors.txt</li>
  <li>Nurses.txt</li>
  <li>Admin.txt</li>
  <li>Patients Data.txt</li>
  <li>Patients Retrive.txt</li>
  <li>Addmat Patients Data.txt</li>
  <li>AddmatPatients Retrive.txt</li>
</ul>

<hr>

<h2>🧱 Technologies Used</h2>
<ul>
  <li>C++</li>
  <li>Object-Oriented Programming (OOP)</li>
  <li>File Handling (fstream)</li>
  <li>STL (vector, string)</li>
</ul>

<hr>

<h2>🏗️ Class Structure</h2>

<h3>Base Class</h3>
<ul>
  <li>Person (name, age, gender, contact)</li>
</ul>

<h3>Derived Classes</h3>
<ul>
  <li>Admin</li>
  <li>Employees
    <ul>
      <li>Doctor</li>
      <li>Nurse</li>
    </ul>
  </li>
  <li>Patient</li>
  <li>AdmittPatients</li>
</ul>

<hr>

<h2>▶️ How to Run</h2>

<ol>
  <li>Clone the repository:</li>
</ol>

<pre>
git clone https://github.com/mharoon1434/Hospital-Management-System-CPP.git
</pre>

<ol start="2">
  <li>Compile:</li>
</ol>

<pre>
g++ main.cpp -o hospital
</pre>

<ol start="3">
  <li>Run:</li>
</ol>

<pre>
./main
</pre>

<hr>

<h2>🔐 Admin File Format</h2>

<pre>
Name
Age
Gender
Contact
Password
</pre>


<h2>👨‍💻 Author</h2>
<p>Muhammad Haroon</p>

<hr>
