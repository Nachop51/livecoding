// const hello = async () => {
// 	await new Promise((resolve) => setTimeout(resolve, 2000));
// 	console.log("termino");
// };

// // setTimeout(() => {
// // 	console.log("Espero dos segundos");
// // });
// // console.log("termino");
// hello();

const fetchData = async () => {
	const response = await fetch(
		"http://www.omdbapi.com/?apikey=b8826283&t=Avengers"
	);
	// .then((res) => res.json())
	// .then((data) => console.log(data));
	const data = await response.json();

	// const data = response.data;

	console.log(data);

	// return data;
};

const anotherFetch = async () => {
	const response = await fetch(
		"http://www.omdbapi.com/?apikey=b8826283&t=Disney"
	);
	const data = await response.json();

	// const data = response.data;

	console.log(data);
};

const start = new Date();
fetchData();
anotherFetch();
const end = new Date();

console.log(end - start);
