<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet  xmlns="http://www.w3.org/1999/xhtml" version="1.1" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
    <style>
      body{
        background-color:lightgrey;
        font-family: Arial;
        font-size: 1rem;
        padding: 0 1rem;
        display: grid;
        place-items: center;
      }
      section{
        background-color:white;
        padding: 5rem;
        margin: 1rem;
        border-radius:3px;
        box-shadow: 0 0 15px rgba(0 ,0,0,0.5);
      }
      h2{
        font-size: 3rem;
        font-weight: bold;
        margin-bottom: 3rem;
      }
      table{
        background-color:lightgreen;
      }
      td{
        padding: 0.8rem;
        border: 2px solid green;
      }
      th{
        padding: 1rem 0;
        text-transform: capitalize;
      }
    </style>
    <section><h2>Users</h2>
      <table>
        <tr >
          <th>id</th>
          <th>name</th>
          <th>dob</th>
          <th>age</th>
          <th>email</th>
          <th>phone</th>
        </tr>
        <xsl:for-each select="users/user">
        <tr>
          <td><xsl:value-of select="id"/></td>
          <td><xsl:value-of select="name"/></td>
          <td><xsl:value-of select="dob"/></td>
          <td><xsl:value-of select="age"/></td>
          <td><xsl:value-of select="email"/></td>
          <td><xsl:value-of select="phone"/></td>
        </tr>
        </xsl:for-each>
      </table></section>
  
  </body>
  </html>
</xsl:template>
</xsl:stylesheet>