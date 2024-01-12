const switchThemeBtn = document.querySelector('.DarkMode');
let toggleTheme = 0;

console.log(toggleTheme)

switchThemeBtn.addEventListener('click', () => {
  if (toggleTheme % 2 == 0) {
    document.documentElement.style.setProperty('--ecriture', '#262626');
    document.documentElement.style.setProperty('--background', '#FAEBD7');
    toggleTheme++;

    const submitButtons = document.querySelectorAll('.submit');

    submitButtons.forEach(button => {
      button.classList.add('black');
    });

  } else {
    document.documentElement.style.setProperty('--ecriture', '#f1f1f1');
    document.documentElement.style.setProperty('--background', '#262626');
    toggleTheme--;

    const submitButtons = document.querySelectorAll('.submit');

    submitButtons.forEach(button => {
      button.classList.remove('black');
    });
  }
});