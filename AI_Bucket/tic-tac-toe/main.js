function Player(name, sym, color, ai)
{
	return {name, sym, color, ai};
}

function State(matrix, sym)
{
	return {matrix, sym};
}

let gameBoard = (function (){
	let matrix = [];
	let players = [];
	let currentPlayer = 0;
	wonFlag = false;
	drawFlag = false;
	hasAI = false;
	gridCells = document.querySelectorAll(".grid-cell");

	let clearDetails = function()
	{
		console.log("In clearDetails...");
		let ips = document.querySelectorAll("input");
		console.log(ips);
		ips.forEach(ip => {
			ip.value = "";
			ip.checked = false;
		});
	}

	let getNamesAndSetup = function()
	{
		let p1Name = document.getElementById("p1-input").value;
		let p2Name = document.getElementById("p2-input").value;
		console.log(p1Name);
		console.log(p2Name);

		let p1 = Player(p1Name, "X", "blue", false);
		let p2 = Player(p2Name, "O", "red", false);
		players = [];
		players.push(p1);
		players.push(p2);

		let aiButtons = document.getElementsByName("ai-choice");
		aiButtons.forEach(btn => {
			if(btn.checked)
			{
				hasAI = true;
				players[Number(btn.value)].ai = true;
			}
		});

		console.log(players);

		let nameDiv = document.querySelector(".name-contents");
		nameDiv.style.display = "none";
		let gameDiv = document.querySelector(".game-contents");
		gameDiv.style.display = "block";
		setupBoard();
	}

	let setupBoard = function(){
		console.log("In setupBoard...");
		matrix = [];
		for(let i = 0; i < 3; i++)
		{
			matrix.push(["", "", ""]);
		}
		currentPlayer = 0;
		wonFlag = false;
		drawFlag = false;
		// add event listeners
		gridCells.forEach(cell => {
			cell.addEventListener("click", makeMove);
			cell.textContent = "";
			cell.disabled = false;
		});
		updateDsp();
		if(hasAI && players[0].ai)
		{
			console.log("Making first move as AI...");
			makeMoveAI();
		}
	}

	let updateDsp = function()
	{
		let dsp = document.getElementById("turn-dsp");
		let player = players[currentPlayer];
		let pName = player.name;
		let pSym = player.sym;
		if(!wonFlag && !drawFlag)
		{
			dsp.textContent = `${pName}'s turn! (${pSym})`;
		}
		else if(wonFlag && !drawFlag)
		{
			dsp.textContent = `${pName} wins!`;
		}
		else
		{
			dsp.textContent = "It's a draw!";
		}
	}

	let isDraw = function(currentMatrix)
	{
		for(let i = 0; i < 3; i++)
		{
			for(let j = 0; j < 3; j++)
			{
				if(currentMatrix[i][j] == "")
				{
					return false;
				}
			}
		}
		return true;
	}

	let hasWonHorz = function(currentMatrix, x)
	{
		let sym = currentMatrix[x][0];
		for(let i = 0; i < 3; i++)
		{
			if(currentMatrix[x][i] != sym || sym == "")
			{
				return false;
			}
		}
		return true;
	}

	let hasWonVert = function(currentMatrix, y)
	{
		let sym = currentMatrix[0][y];
		for(let i = 0; i < 3; i++)
		{
			if(currentMatrix[i][y] != sym || sym == "")
			{
				return false;
			}
		}
		return true;
	}

	let hasWonDiag = function(currentMatrix, x, y)
	{
		if((y == 1 && (x == 0 || x == 2)) || (x == 1 && (y == 0 || y == 2)) || currentMatrix[x][y] == "")
		{
			return false;
		}
		else
		{
			let diag1 = [currentMatrix[0][0], currentMatrix[1][1], currentMatrix[2][2]];
			let diag2 = [currentMatrix[0][2], currentMatrix[1][1], currentMatrix[2][0]];
			let diag1Set = new Set(diag1);
			let diag2Set = new Set(diag2);
			if(diag1Set.has("") && diag2Set.has(""))
			{
				return false;
			}
			return diag1Set.size == 1 || diag2Set.size == 1;
		}
	}

	let lockBoard = function()
	{
		gridCells.forEach(cell => {
			cell.disabled = true;
		});
	}

	let winCheck = function(x, y)
	{
		console.log(hasWonHorz(matrix, x) + " " + hasWonVert(matrix, y) + " " + hasWonDiag(matrix, x,y));
		console.log(matrix);
		let won = hasWonHorz(matrix, x) || hasWonVert(matrix, y) || hasWonDiag(matrix, x, y);
		if(won)
		{
			lockBoard();
			wonFlag = true;
			updateDsp();
		}
		else if(isDraw(matrix))
		{
			wonFlag = false;
			drawFlag = true;
			updateDsp();
		}
	}

	let makeMove = function()
	{
		// is event listener for the buttons
		// on click, checks current player, draws symbol, disables
		console.log("In makeMove...");
		console.log(matrix);
		let sym = players[currentPlayer].sym;
		this.style.color = players[currentPlayer].color;
		this.textContent = sym;
		let x = Number(this.value.substring(0,1));
		let y = Number(this.value.substring(1));
		matrix[x][y] = sym;
		this.disabled = true;
		winCheck(x, y);
		if(!wonFlag && !drawFlag)
		{
			currentPlayer = (currentPlayer + 1) % 2;
			updateDsp();
			if(hasAI && players[currentPlayer].ai)
			{
				console.log("About to call makeMoveAI...");
				console.log(matrix);
				makeMoveAI();
			}
		}
	}

	let matCopy = function(mat)
	{
		newMat = []
		mat.forEach(subArr => {
			newMat.push(subArr.slice());
		})
		return newMat;
	}

	let utility = function(stateObj) // 1 if MAX wins, -1 if MIN wins, 0 for draw, 2 if non-terminal
	{
		for(let i = 0; i < 3; i++)
		{
			if(hasWonHorz(stateObj.matrix, i))
			{
				if(stateObj.matrix[i][0] == "X")
				{
					return 1;
				}
				else
				{
					return -1;
				}
			}
		}
		for(let j = 0; j < 3; j++)
		{
			if(hasWonVert(stateObj.matrix, j))
			{
				if(stateObj.matrix[0][j] == "X")
				{
					return 1;
				}
				else
				{
					return -1;
				}
			}
		}
		if(hasWonDiag(stateObj.matrix, 1,1))
		{
			if(stateObj.matrix[1][1] == "X")
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		if(isDraw(stateObj.matrix))
		{
			return 0;
		}
		return 2;
	}

	let actions = function(stateObj)
	{
		let moves = [];
		for(let i = 0; i < 3; i++)
		{
			for(let j = 0; j < 3; j++)
			{
				if(stateObj.matrix[i][j] == "")
				{
					moves.push([i, j]);
				}
			}
		}
		return moves;
	}

	let result = function(stateObj, move)
	{
		let newSym = "O";
		if(stateObj.sym == "O")
		{
			newSym = "X";
		}
		let newState = State(matCopy(stateObj.matrix), newSym);
		newState.matrix[move[0]][move[1]] = stateObj.sym;
		return newState;
	}

	let maxMove = function(stateObj, prevAction)
	{
		let util = utility(stateObj)
		if(util != 2)
		{
			return [util, prevAction];
		}
		let v = -Infinity;
		let bestAction = [];
		let actionList = actions(stateObj);
		actionList.forEach(action => {
			let newV = minMove(result(stateObj, action), action)[0];
			if(newV > v)
			{
				v = newV;
				bestAction = action.slice();
			}
		});
		return [v, bestAction];
	}

	let minMove = function(stateObj, prevAction)
	{
		let util = utility(stateObj);
		if(util != 2)
		{
			return [util, prevAction];
		}
		let v = Infinity;
		let bestAction = [];
		let actionList = actions(stateObj);
		actionList.forEach(action => {
			let newV = maxMove(result(stateObj, action), action)[0];
			if(newV < v)
			{
				v = newV;
				bestAction = action.slice();
			}
		});
		return [v, bestAction];
	}

	let makeMoveAI = function()
	{
		console.log("Tremble before the AI!");
		let move = [];
		let currentSym = players[currentPlayer].sym;
		let currentState = State(matCopy(matrix), currentSym);

		if(currentPlayer == 0)
		{
			move = maxMove(currentState, []);
		}
		else
		{
			move = minMove(currentState, []);
		}
		console.log("The AI made this move:")
		console.log({move});
		let cellCoords = move[1].join("");
		console.log(cellCoords);

		let cellToMove = document.querySelector(`button[value="${cellCoords}"]`);
		matrix[move[1][0]][move[1][1]] = currentSym;
		cellToMove.textContent = currentSym;
		cellToMove.disabled = true;
		cellToMove.style.color = players[currentPlayer].color;
		console.log(matrix);
		winCheck(move[1][0], move[1][1]);
		if(!wonFlag)
		{
			currentPlayer = (currentPlayer + 1) % 2;
			updateDsp();
		}
	}

	return {setupBoard: setupBoard, getNamesAndSetup: getNamesAndSetup, clearDetails:clearDetails };
})();

let ngButton = document.getElementById("rst");
let nameButton = document.getElementById("name-btn");
let clrButton = document.getElementById("clr-btn");
ngButton.onclick = gameBoard.setupBoard;
nameButton.onclick = gameBoard.getNamesAndSetup;
clrButton.onclick = gameBoard.clearDetails;