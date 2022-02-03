import mysql from "mysql"

export const db = mysql.createConnection({
	host: "localhost",
	user: "root",
	password: "",
	database: "wtl5",
})

db.connect((err) => {
	if (err) console.log(err)
})
