from PIL import Image
import numpy as np


def loading_and_processing_image(path):
    rotated_image = Image.open(path).convert("1")
    return np.array(rotated_image)


def find_height_point(image_matrix):
    for i in range(image_matrix.shape[0]):
        for j in range(image_matrix.shape[1]):
            if not image_matrix[i, j]:
                return [i, j]


def find_lower_point(image_matrix):
    for i in range(image_matrix.shape[0]):
        for j in range(image_matrix.shape[1]):
            if not image_matrix[image_matrix.shape[0] - i - 1, j]:
                return [image_matrix.shape[0] - i - 1, j]


def find_left_point(image_matrix):
    for j in range(image_matrix.shape[1]):
        for i in range(image_matrix.shape[0]):
            if not image_matrix[i, j]:
                return [i, j]


def find_right_point(image_matrix):
    for j in range(image_matrix.shape[1]):
        for i in range(image_matrix.shape[0]):
            if not image_matrix[i, image_matrix.shape[1] - j - 1]:
                return [i, image_matrix.shape[1] - j - 1]


def find_corner(height_point, lower_point, left_point, right_point): #!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if left_point[0] < right_point[0]:
        corner1 = np.arctan((left_point[0] - height_point[0])/(height_point[1] - left_point[1]))
        corner2 = np.arctan((lower_point[0] - right_point[0])/(right_point[1] - lower_point[1]))
        return (corner1 + corner2)/2
    else:
        corner1 = np.arctan((right_point[0] - height_point[0]) / (right_point[1] - height_point[1]))
        corner2 = np.arctan((lower_point[0] - left_point[0]) / (lower_point[1] - left_point[1]))
        return (corner1 + corner2) * 90 / np.pi


def rotate_image(path, corner):
    image = Image.open(path).rotate(corner, resample=Image.BICUBIC, expand=True)

    return image(Image.fromarray(np.tile(np.array([255, 255, 255, 1]), (image))))






PATH = "image.9ESAJ2.png"
rotated_image_matrix = loading_and_processing_image(PATH)
height = find_height_point(rotated_image_matrix)
lower = find_lower_point(rotated_image_matrix)
left = find_left_point(rotated_image_matrix)
right = find_right_point(rotated_image_matrix)
corner = find_corner(height, lower, left, right)
print(corner)
rotate_image(PATH, corner).show()
