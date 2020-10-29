var bgX = 0;
var baseX = 0;
var state = 0;
var bird = {};
var timeCnt = 0;
var pipes = [];
var score = 0;
const level2 = 11;

function preload() {
    bgImgs = [loadImage("assets/sprites/background-day.png"),
        loadImage("assets/sprites/background-night.png")];
    bgImg = bgImgs[0];
    baseImg = loadImage("assets/sprites/base.png");
    msgImg = loadImage("assets/sprites/message.png");
    overImg = loadImage("assets/sprites/gameover.png");
    birds = [];
    ["blue", "red", "yellow"].forEach((i) => {
        ["down", "mid", "up"].forEach((j) => {
            let path = `assets/sprites/${i}bird-${j}flap.png`;
            birds.push(loadImage(path));
    })});
    pipeImgs = [];
    ["green", "red"].forEach((i) => {
        pipeImgs.push(loadImage(`assets/sprites/pipe-${i}-lower.png`));
        pipeImgs.push(loadImage(`assets/sprites/pipe-${i}-lower.png`));
    })
    scoreImgs = [];
    for (let i = 0; i < 10; i++) {
        scoreImgs.push(loadImage(`assets/sprites/${i}.png`));
    }
    dieSound = loadSound("assets/audio/die.ogg");
    hitSound = loadSound("assets/audio/hit.ogg");
    pointSound = loadSound("assets/audio/point.ogg");
    swooshSound = loadSound("assets/audio/swoosh.ogg");
    wingSound = loadSound("assets/audio/wing.ogg");
}

function setup() {
    createCanvas(640, 480);
    let cvsWrapper = document.getElementById("canvasWrapper");
    let myCanvas = createCanvas(
        cvsWrapper.offsetWidth,
        cvsWrapper.offsetHeight
    );
    myCanvas.parent(cvsWrapper);
    bgScale = width / bgImg.width;
    baseDisplayW = width;
    baseDisplayH = width / baseImg.width * baseImg.height;
    baseTop = height - baseDisplayH;
    let msgScale = width / msgImg.width * 0.9;
    msgDisplayW = msgImg.width * msgScale;
    msgDisplayH = msgImg.height * msgScale;
    msgTop = msgLeft = (width - msgDisplayW) / 2;
    let overScale = width / overImg.width * 0.9;
    overDisplayW = overImg.width * overScale;
    overDisplayH = overImg.height * overScale;
    overLeft = (width - overDisplayW) / 2;
    overTop = 0.2 * height;
    pipeDisplayW = pipeImgs[0].width*bgScale;
    pipeDisplayH = pipeImgs[0].height*bgScale;
    for (let i = 0; i<4; i+=2) {
        let w = pipeImgs[0].width;
        let h = pipeImgs[0].height;
        pipeImgs[i].loadPixels();
        pipeImgs[i+1].loadPixels();
        for (let hi=0; hi < h; hi++) {
            for (let wi = 0; wi < w; wi++) {
                for (let _ = 0; _ < 4; _++) {
                    pipeImgs[i].pixels[hi*w*4+wi*4+_] = pipeImgs[i+1].pixels[(h-hi-1)*w*4+wi*4+_];
                }
            }
        }
        pipeImgs[i].updatePixels();
    }
    birdDisplayW = birds[0].width * bgScale;
    birdDisplayH = birds[0].height * bgScale;
    bird.reset = () => {
        bird.x = width / 2;
        bird.y = height / 2;
        bird.vy = 0;
        bird.ay = 0;
        bird.slope = 0;
        bird.dslope = 0;
        bird.ddslope = 0;
        bird.id = Math.floor(Math.random()*3);
        bird.img = birds[bird.id*3+1];
        bird.wingCnt = 1;
        state = 0;
    }
    bird.fly = () => {
        bird.vy = -6;
        bird.ay = .3;
        bird.slope = -1;
        bird.dslope = .04;
        bird.ddslope = .0007;
        bird.wingCnt = 0;
        wingSound.play();
        state = 1;
    }
    bird.die = () => {
        bird.img = birds[bird.id*3+1];
        dieSound.play();
        hitSound.play();
        state = 2;
    }
    bird.ground = () => {
        bird.vy = 0;
        bird.ay = 0;
        bird.dslope = 0;
        bird.ddslope = 0;
        state = 3;
    }
    bird.reset();
}

function draw() {
    // calculate
    bgDx = -.5;
    baseDx = -3;
    if (state === 0 || state === 1) {
        bgX = bgX+bgDx <= -width ? bgX+bgDx+width : bgX+bgDx;
        bird.wingCnt = bird.wingCnt+1 >= 15 ? 0: bird.wingCnt+1;
        bird.img = birds[bird.id*3+Math.floor(bird.wingCnt/5)];
        baseX = baseX+baseDx <= -width ? baseX+baseDx+width : baseX+baseDx;

        if (state === 1) {
            pipes.forEach((pipe) => { pipe.x += baseDx; });
            if (pipes.length === 0 ||
                pipes[pipes.length-1].x + pipeDisplayW*4.5 < width) {
                let space = Math.random()*(baseTop - birdDisplayH * 8);
                pipes.push({x: width, y: space + 2 * birdDisplayH, got: false,
                r0: Math.random()*PI*2});
            }
        }
    }
    timeCnt++;
    bird.vy += bird.ay;
    bird.y += bird.vy;
    bird.dslope += bird.ddslope;
    bird.slope += bird.dslope;

    // background
    background(0);
    image(bgImg, bgX, 0, width, height);
    image(bgImg, bgX + width, 0, width, height);
    // pipe
    for (let i = 0; i < pipes.length; i++) {
        let pipe = pipes[i];
        if (i < level2-1) {
            image(pipeImgs[0], pipe.x, pipe.y-pipeDisplayH, pipeDisplayW, pipeDisplayH);
            image(pipeImgs[1], pipe.x, pipe.y+birdDisplayH*4, pipeDisplayW, pipeDisplayH);
        } else {
            pipe.y += sin(timeCnt/50+pipe.r0) * 0.7;
            image(pipeImgs[2], pipe.x, pipe.y-pipeDisplayH, pipeDisplayW, pipeDisplayH);
            image(pipeImgs[3], pipe.x, pipe.y+birdDisplayH*4, pipeDisplayW, pipeDisplayH);
        }
    };
    // base
    image(baseImg, baseX, baseTop, baseDisplayW, baseDisplayH);
    image(baseImg, baseX + width, baseTop, baseDisplayW, baseDisplayH);

    // bird
    push();
    imageMode(CENTER);
    translate(bird.x, bird.y);
    rotate(atan(bird.slope));
    image(bird.img, 0, 0, bird.img.width*bgScale, bird.img.height*bgScale);
    pop();
    if (bird.y + birdDisplayH/2 > baseTop && state < 3) {
        if (state === 1)
            bird.die();
        bird.ground();
    }
    if (state === 1) {
        pipes.forEach((pipe) => {
            if (pipe.x < bird.x+birdDisplayW/2*0.8 &&
                pipe.x+pipeDisplayW > bird.x-birdDisplayW/2*0.8 &&
                (pipe.y > bird.y-birdDisplayH/2 ||
                    pipe.y + 4*birdDisplayH < bird.y+birdDisplayH/2)) {
                bird.die();
            }
            if (pipe.x+pipeDisplayW < bird.x-birdDisplayW/2 &&
                ! pipe.got) {
                pipe.got = true;
                score++;
                pointSound.play();
            }
        });
    }
    // message
    if (state === 0) {
        image(msgImg, msgLeft, msgTop, msgDisplayW, msgDisplayH);
    } else if (state === 3) {
        image(overImg, overLeft, overTop, overDisplayW, overDisplayH);
    }
    // score
    if (state === 1 || state === 2 || state ===3)
        showScore();
}

function keyPressed() {
    if (keyCode === 32) {
        if (state === 0) {
            bird.fly();
        } else if (state === 1) {
            bird.fly();
        } else if (state === 3) {
            bird.reset();
            pipes = [];
            score = 0;
            timeCnt = 0;
            bgImg = bgImgs[Math.floor(Math.random()*2)];
        }
    }
}

function showScore() {
    let nl = [];
    let _score = score;
    while (_score > 0 || nl.length === 0) {
        nl.push(_score % 10);
        _score = Math.floor(_score/10);
    }
    nl.reverse();
    nl = nl.map(n => scoreImgs[n]);
    let wSum = bgScale*nl.map(n=>n.width).reduce((accu, curr) => accu + curr);
    let x = (width - wSum)/2;
    let y = state === 3 ? .4*height : .1*height;
    nl.forEach((n) => {
        image(n, x, y, n.width*bgScale, n.height*bgScale);
        x += n.width*bgScale;
    });
}
