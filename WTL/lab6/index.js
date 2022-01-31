import express from "express"
import { db } from "./db.js"
const PORT = 8081

const app = express()

app.use(express.static("static"))
app.use(express.json())

app.get("/tasks", async (req, res) => {
	let sql = "SELECT * FROM tasks"
	db.query(sql, (err, result) => {
		if (err) {
			console.log(err)
			return res.send({ ok: false })
		}
		res.send({ ok: true, tasks: result })
	})
})

app.post("/tasks", async (req, res) => {
	const { task } = req.body
	let sql = `insert into tasks (action, description, remind_at) values ('${task}','',now())`
	db.query(sql, (err, result) => {
		if (err) {
			console.log(err)
			return res.send({ ok: false })
		}
		db.query("select LAST_INSERT_ID() as id", (err, id) => {
			if (err) {
				console.log(err)
				return res.send({ ok: false })
			}
			res.send({ ok: true, task: { id: id[0]["id"], task } })
		})
	})
})

app.put("/tasks/:id", async (req, res) => {
	const { task } = req.body
	const task_id = req.params.id
	let sql = `update tasks set action = '${task}' where id = ${task_id}`
	db.query(sql, (err, result) => {
		if (err) {
			console.log(err)
			return res.send({ ok: false })
		}
		res.send({ ok: true })
	})
})

app.delete("/tasks/:id", async (req, res) => {
	let sql = "DELETE FROM tasks where id = " + req.params.id
	db.query(sql, (err) => {
		if (err) {
			console.log(err)
			return res.send({ ok: false })
		}
		res.send({ ok: true })
	})
})

app.listen(PORT, () => {
	console.log(`[server] Live at http://localhost:${PORT}`)
})
