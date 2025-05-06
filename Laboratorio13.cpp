#include "stdafx.h"
#include "pch.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

int main(array<System::String^>^ args)
{
    // Cambiar "master" por "Escuela"
    String^ cadenaConexion = "Server=localhost\\SQLEXPRESS02;Database=Escuela;Trusted_Connection=True;";
    SqlConnection^ conexion = gcnew SqlConnection(cadenaConexion);

    try
    {
        conexion->Open();
        Console::WriteLine("Conexión exitosa a la base de datos.");

        String^ consulta = "SELECT * FROM Estudiantes";
        SqlCommand^ comando = gcnew SqlCommand(consulta, conexion);
        SqlDataReader^ lector = comando->ExecuteReader();

        while (lector->Read())
        {
            Console::WriteLine("ID: {0}, Nombre: {1}, Edad: {2}",
                lector["Id"], lector["Nombre"], lector["Edad"]);
        }

        lector->Close();  // Buen hábito: cerrar el lector antes de cerrar la conexión
        conexion->Close();
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Error: {0}", ex->Message);
    }

    Console::ReadLine();
    return 0;
}
