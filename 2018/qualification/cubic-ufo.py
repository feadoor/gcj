from math import sqrt

def get_normal_vector(area):
    y = area / 3 + 2 * sqrt(1 / 6 - area * area / 18)
    x = area / 3 - sqrt(1 / 6 - area * area / 18)
    return (x, y, x)

def get_rotation_matrix(normal):
    x, y, z = normal
    return (
        ((1 + y - x * x) / (1 + y), -x, (-1 * x * z) / (1 + y)),
        (x, (1 + y - x * x - z * z) / (1 + y), z),
        ((-1 * x * z) / (1 + y), -z, (1 + y - z * z) / (1 + y)),
    )

def get_face_centres(matrix):
    return (
        (matrix[0][0] / 2, matrix[1][0] / 2, matrix[2][0] / 2),
        (matrix[0][1] / 2, matrix[1][1] / 2, matrix[2][1] / 2),
        (matrix[0][2] / 2, matrix[1][2] / 2, matrix[2][2] / 2),
    )

def do_test_case(case):
    area = float(input())
    faces = get_face_centres(get_rotation_matrix(get_normal_vector(area)))
    print("Case #{0}:".format(case))
    for face in faces:
        print("{0} {1} {2}".format(face[0], face[1], face[2]))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == "__main__":
    main()
