
var images = document.images;

function load(image) {
    
    var downloadImage = new Image();
    downloadImage.src = image.src;
    
    downloadImage.onload = function() {
        image.src = this.src;
    };
    image.src = '%@';
}

for (i = 0; i < images.length; i++) {
    load(images[i]);
}
