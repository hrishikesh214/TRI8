error_box = ["username", "email", "password", "gender"]

function $(x) {
	return document.getElementById(x)
}

function __(x) {
	return document.getElementsByName(x)[0]
}

const put_error = (label, msg) => {
	$(`error:${label}`).innerHTML = msg
}

function register_user() {
	// flush error boxes
	error_box.forEach((x) => {
		$(`error:${x}`).innerHTML = ""
	})

	var username = __("username").value ?? ""
	var pass = __("password").value ?? ""
	var email = __("email").value ?? ""
	var gender = $("male").checked
		? "male"
		: $("female").checked
		? "female"
		: null

	// validate form
	has_error = false
	if (username.length < 3) {
		has_error = true
		put_error("username", "Length must be atleast 3")
	}
	if (!email.match(/^[\w-\.]+@([\w-]+\.)+[\w-]{2,3}$/)) {
		has_error = true
		put_error("email", "Invalid email")
	}
	if (pass.length < 6) {
		has_error = true
		put_error("password", "Length must be atleast 6")
	}
	if (gender == null) {
		has_error = true
		put_error("gender", "Please select gender")
	}
	if (has_error) return console.log("Validation failed!")

	// now send it to api
	alert("Success!")
	window.location.href = `mailto:${email}`
}
