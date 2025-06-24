<!DOCTYPE html>
<html lang="id">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>Pesan Cinta Interaktif</title>
  <style>
    body {
      background-color: #ffe6e6;
      font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
      text-align: center;
      padding-top: 100px;
      overflow: hidden;
      position: relative;
    }

    h1 {
      font-size: 48px;
      color: crimson;
      margin-bottom: 10px;
      z-index: 1;
      position: relative;
    }

    h2 {
      font-size: 28px;
      color: #b30059;
      margin-bottom: 40px;
      z-index: 1;
      position: relative;
    }

    #result {
      font-size: 32px;
      color: #ff0066;
      margin-top: 30px;
      display: none;
      z-index: 1;
      position: relative;
    }

    button {
      font-size: 20px;
      padding: 10px 25px;
      margin: 10px;
      border: none;
      border-radius: 10px;
      cursor: pointer;
      transition: 0.3s;
      position: relative;
      z-index: 1;
    }

    .yes {
      background-color: #ff66b2;
      color: white;
    }

    .no {
      background-color: #999;
      color: white;
      position: absolute;
    }

    .yes:hover {
      background-color: #ff3385;
    }

    /* Falling hearts */
    .heart {
      position: fixed;
      top: -10px;
      color: #ff3399;
      font-size: 24px;
      animation: fall 5s linear infinite;
      z-index: 0;
    }

    @keyframes fall {
      to {
        transform: translateY(100vh) rotate(360deg);
        opacity: 0;
      }
    }
  </style>
</head>
<body>

  
  <h2>Celsi sayang Cava</h2>

  <button class="yes" onclick="showLove()">YA</button>
  <button class="no" id="noBtn">TIDAK</button>

  <div id="result"> Cieee Cieee Celsii uhuyyy ❤️</div>

  <!-- Musik romantis bebas lisensi dari Bensound -->
  <audio id="romanticMusic" autoplay loop>
    <source src="https://www.bensound.com/bensound-music/bensound-tenderness.mp3" type="audio/mp3">
    Browser Anda tidak mendukung audio.
  </audio>

  <script>
    function showLove() {
      document.getElementById("result").style.display = "block";
    }

    const noBtn = document.getElementById("noBtn");

    noBtn.addEventListener("mouseover", () => {
      const maxX = window.innerWidth - noBtn.offsetWidth;
      const maxY = window.innerHeight - noBtn.offsetHeight;

      const randX = Math.floor(Math.random() * maxX);
      const randY = Math.floor(Math.random() * maxY);

      noBtn.style.left = randX + "px";
      noBtn.style.top = randY + "px";
    });

    function createHeart() {
      const heart = document.createElement('div');
      heart.classList.add('heart');
      heart.textContent = '💖';
      heart.style.left = Math.random() * 100 + 'vw';
      heart.style.animationDuration = (Math.random() * 3 + 3) + 's';
      document.body.appendChild(heart);

      setTimeout(() => {
        heart.remove();
      }, 5000);
    }

    setInterval(createHeart, 300);

    // Autoplay fix for browser that block it
    window.addEventListener('click', () => {
      const music = document.getElementById("romanticMusic");
      if (music.paused) {
        music.play();
      }
    });
  </script>

</body>
</html>
