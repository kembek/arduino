const button = document.querySelector("button");
const buttonArg = document.querySelector(".secondary");

button.addEventListener("click", function(){
	const command = {
		command: "G"
	}

	fetch("/send", {
		method: "POST",
		body: JSON.stringify(command),
		headers: {
			"Content-Type": "application/json"
		}
	}).then(
		({ data })=> console.log("success", data),
		({ response }) => console.log("error", response)

	);
});


buttonArg.addEventListener("click", function(){
	alert("Click secondary");
	fetch("/?name='gangsta'");
});

