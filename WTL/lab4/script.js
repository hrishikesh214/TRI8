function $(x) {
	return document.querySelector(x)
}

function sleep(ms) {
	return new Promise((resolve, reject) => setTimeout(resolve, ms))
}

// start live clock
const clock = $("#clock")
setInterval(() => {
	const date = new Date()
	clock.innerText = date.toLocaleTimeString()
}, 1000)

function toggle_info() {
	const info = $("#info")
	if (info.innerText == "")
		info.innerText =
			"This content was not present here. It is actually injected here by javascript DOM. With DOM you can do any change in HTML Document in real-time only at client side."
	else info.innerText = ""
}

async function roll_dice() {
	const dice_val = $("#dice_val")
	let count = Math.floor(Math.random() * 20) + 5
	for (let i = 0; i < count; i++) {
		let val = Math.floor(Math.random() * 6)
		dice_val.innerText = val + 1
		await sleep(100)
	}
}

function change_color(x) {
	const ele = $(".bgchange")
	let color = x ? $("#text-change").value : $("#bg-change").value
	if (x) ele.style.color = color
	else ele.style.backgroundColor = color
}

const get_color = (animate_time) => {
	animate_time =
		animate_time == -1 ? 0 : animate_time == -2 ? 5500 : animate_time
	switch (animate_time) {
		case 0:
			return [-1, "aquamarine", 1000]
		case 1000:
			return [0, "#f8a42f", 2000]
		case 2000:
			return [1000, "#ffd729", 3500]
		case 3500:
			return [2000, "#ff4605", 5500]
		case 5500:
			return [3500, "#860111", -2]
		default:
			return [2000, "#ff4605", 5500]
	}
}

//======== heat box =================
var animate_time = 0
var is_heating = false

async function start_heating() {
	is_heating = true
	$(".heat-content").innerText = "Heating..."
	const ele = $(".heat")
	var is_done = false
	while (is_heating && !is_done) {
		let [prev_time, color, next_time] = get_color(animate_time)
		ele.style.backgroundColor = color
		animate_time = next_time
		await sleep(next_time - prev_time)
		if (next_time == -2) {
			$(".heat-content").innerText = "Heated up!"
			is_done = true
		}
	}
}

async function stop_heating() {
	is_heating = false
	$(".heat-content").innerText = "Cooling..."
	const ele = $(".heat")
	var is_done = false
	while (!is_heating && !is_done) {
		let [prev_time, color, next_time] = get_color(animate_time)
		ele.style.backgroundColor = color
		animate_time = prev_time
		await sleep(next_time - prev_time)
		if (prev_time == -1) {
			$(".heat-content").innerText = "Cooled down!"
			setTimeout(() => {
				!is_heating && ($(".heat-content").innerText = "")
			}, 1500)
			is_done = true
		}
	}
}
