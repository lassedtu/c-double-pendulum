#include <raylib.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGH 600

#define BALL_RADIUS 15
#define LINE_THICKNESS 3
#define L1 250
#define L2 200
#define M1 10
#define M2 15
#define G 1000.0f

float l1, l2, phi1, phi2, phi1_d, phi2_d, phi1_dd, phi2_dd, m1, m2;

Vector2 getPivot(float angle, float length, Vector2 pivot)
{
    Vector2 newPivot;
    newPivot.x = pivot.x + length * sinf(angle);
    newPivot.y = pivot.y + length * cosf(angle);
    return newPivot;
}

Vector2 drawPendulum(float angle, float length, Vector2 pivot)
{
    Vector2 newPivot = getPivot(angle, length, pivot);
    DrawLineEx(pivot, newPivot, LINE_THICKNESS, WHITE);
    DrawCircle(newPivot.x, newPivot.y, BALL_RADIUS, BLUE);
    return newPivot;
}

void drawDoublePendulum(float phi1, float phi2, float length1, float length2, Vector2 pivot)
{
    Vector2 pivot1 = getPivot(phi1, length1, pivot);

    // Draw second arm first to preserve layering order.
    drawPendulum(phi2, length2, pivot1);

    drawPendulum(phi1, length1, pivot);
}

void initSolver(void)
{
    l1 = L1;
    l2 = L2;
    phi1 = GetRandomValue(-90, 90) * DEG2RAD;
    phi2 = GetRandomValue(-180, 180) * DEG2RAD;
    phi1_d = 0;
    phi2_d = 0;
    m1 = M1;
    m2 = M2;
}

void step(void)
{
    // Angular acceleration
    phi1_dd = (-G * (2 * m1 + m2) * sinf(phi1) - m2 * G * sinf(phi1 - 2 * phi2) - 2 * sinf(phi1 - phi2) * m2 * (phi2_d * phi2_d * l2 + phi1_d * phi1_d * l1 * cosf(phi1 - phi2))) / (l1 * (2 * m1 + m2 - m2 * cosf(2 * phi1 - 2 * phi2)));

    phi2_dd = (2 * sinf(phi1 - phi2) * (phi1_d * phi1_d * l1 * (m1 + m2) + G * (m1 + m2) * cosf(phi1) + phi2_d * phi2_d * l2 * m2 * cosf(phi1 - phi2))) / (l2 * (2 * m1 + m2 - m2 * cosf(2 * phi1 - 2 * phi2)));

    // Angular velocity
    phi1_d += phi1_dd * GetFrameTime();
    phi2_d += phi2_dd * GetFrameTime();

    // Angle
    phi1 += phi1_d * GetFrameTime();
    phi2 += phi2_d * GetFrameTime();
}

int main(void)
{
    InitWindow(WIDTH, HEIGH, "Double Pendulum Simulation");
    SetTargetFPS(60);

    initSolver();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        drawDoublePendulum(phi1, phi2, l1, l2, (Vector2){WIDTH / 2, 0});
        step();

        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
