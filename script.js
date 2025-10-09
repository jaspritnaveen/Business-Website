const backToTopBtn = document.getElementById("backToTopBtn");

window.addEventListener("scroll", () => {
  if (window.scrollY > 100) {
    backToTopBtn.classList.remove("d-none"); 
  } else {
    backToTopBtn.classList.add("d-none"); 
  }
});
