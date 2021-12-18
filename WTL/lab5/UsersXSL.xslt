<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.1" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
  <h2>Users</h2>
  <table border="1">
    <tr bgcolor="#9acd32">
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
  </table>
  </body>
  </html>
</xsl:template>
</xsl:stylesheet>