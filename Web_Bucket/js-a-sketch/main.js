function drawGrid(nCells)
{
	const drScreen = document.querySelector(".draw-screen");
	drScreen.innerHTML = ""; //delete any existing cells
	drScreen.style.gridTemplateColumns = `repeat(${nCells}, auto)`;
	drScreen.style.gridTemplateRows = `repeat(${nCells}, auto)`;

	for(let i = 0; i < nCells * nCells; i++)
	{
		let cell = document.createElement("div");
		cell.style = "border-style: solid; border-width: 1px;";
		cell.classList.add("sketch-cell");
		cell.nAccessLeft = 10;
		cell.addEventListener("mouseover", colourise);
		drScreen.appendChild(cell);
	}
}

function colourise(e)
{
	let colorVal = e.target.nAccessLeft;
	colorVal *= 10; //start from rgb values of 100
	e.target.style.backgroundColor = `rgb(${colorVal}, ${colorVal}, ${colorVal})`;
	if(e.target.nAccessLeft) //prevent it from becoming negative
	{
		e.target.nAccessLeft--; //go down to 0
	}
}

function clear()
{
	const cells = Array.from(document.querySelectorAll(".sketch-cell"));
	console.log(cells);
	cells.forEach(cell => {
		cell.style.backgroundColor = "white";
	});
}

function newGrid()
{
	nCells = prompt("Enter number of cells per side. WARNING: Values over 400 may cause instability!");
	clear();
	drawGrid(nCells);
}


function init()
{
	document.getElementById("reset").addEventListener("click", clear);
	document.getElementById("new").addEventListener("click", newGrid);
	drawGrid(16);
}

init();


