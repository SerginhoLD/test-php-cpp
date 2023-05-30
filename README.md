# Тестовое расширение для php 8.2

[Расширение на C++](docker/php/sld)

[Сборка Dockerfile](docker/php/Dockerfile)

[Использование в PHP](html/index.php)

```php
/**
* Равномерное изменение размера по большей стороне
* @method thumbnail(string $newPath, int $width, int $height)
*/
$image = new \SerginhoLD\OpenCV(__DIR__ . '/php.png');
$thumb = $image->thumbnail(__DIR__ . '/php300.png', 300, 300);
```
