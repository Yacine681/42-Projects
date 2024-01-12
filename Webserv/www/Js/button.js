const errorsButton = document.getElementById('errorsButton');

errorsButton.addEventListener('click', () => {
  window.location.href = 'errors.html';
});

const cppButton = document.getElementById('cppButton');

cppButton.addEventListener('click', () => {
  window.location.href = 'cpp.html';
});

const subButton = document.getElementById('subButton');

subButton.addEventListener('click', () => {
  window.location.href = 'inscription.html';
});

const pythonButton = document.getElementById('pythonButton');

pythonButton.addEventListener('click', () => {
  window.location.href = 'python.html';
});

const redirectionButton = document.getElementById('redirectionButton');

redirectionButton.addEventListener('click', () => {
  window.location.href = 'redirection.html';
});

const Home = document.getElementById('Home');

if (Home != null)
{
  Home.addEventListener('click', () => {
    window.location.href = 'index.html';
  });
}

const uploadButton = document.getElementById('uploadButton');

uploadButton.addEventListener('click', () => {
  window.location.href = 'upload.html';
});
