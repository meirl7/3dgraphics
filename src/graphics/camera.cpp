#include "camera.hpp"

Camera::Camera()
{
    position = glm::vec3(0.0f, 2.0f, 5.0f);
    pitch = 0.0f;
    yaw = 0.0f;
    mouseSensitivity = 0.1f;
    fov = 45.0f;
    movementSpeed = 25.f;
    front = glm::vec3(0.0f, 0.f, -1.0f);
    worldup = glm::vec3(0.0f, 1.0f, 0.0f);
    update();
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

void Camera::update()
{
    glm::vec3 f;
    f.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    f.y = sin(glm::radians(pitch));
    f.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(f);

    //fr.x = cos(glm::radians(yaw));
    //fr.z = sin(glm::radians(yaw));
    
    right = glm::normalize(glm::cross(front, worldup));
    up = glm::normalize(glm::cross(right, front));
}
