CREATE OR REPLACE PROCEDURE P_REGISTRAR_CLIENTE (
    P_NOMBRE           IN     VARCHAR2,
    P_APELLIDO1        IN     VARCHAR2,
    P_APELLIDO2        IN     VARCHAR2,
    P_USUARIO          IN     VARCHAR2,
    P_PROGRAMA         IN     VARCHAR2,
    P_NUMBERO_TELEFONO IN     VARCHAR2)
AS
    LV_AGREGADO_POR      VARCHAR2(25)      := USER;
    LV_AGREGADO_EN       DATE              :=  SYSDATE;
    LR_REGISTRO_CLIENTE  CLIENTES%ROWTYPE;
    LR_REGISTRO_TELEFONO TELEFONOS%ROWTYPE;
BEGIN
    LR_REGISTRO_CLIENTE.ID         := S_ID_CLIENTES.NEXTVAL;
    LR_REGISTRO_CLIENTE.NOMBRE     := P_NOMBRE;
    LR_REGISTRO_CLIENTE.APELLIDO1  := P_APELLIDO1;
    LR_REGISTRO_CLIENTE.APELLIDO2  := P_APELLIDO1;
    LR_REGISTRO_CLIENTE.USUARIO    := P_USUARIO;
    LR_REGISTRO_CLIENTE.PROGRAMA   := P_PROGRAMA;
    LR_REGISTRO_CLIENTE.CREADO_POR := LV_AGREGADO_POR;
    LR_REGISTRO_CLIENTE.CREADO_EN  := LV_AGREGADO_EN;
    INSERT INTO CLIENTES VALUES LR_REGISTRO_CLIENTE;

    LR_REGISTRO_TELEFONO.ID         := S_ID_TELEFONOS.NEXTVAL;
    LR_REGISTRO_TELEFONO.NUMBERO    := P_NUMBERO_TELEFONO;
    LR_REGISTRO_TELEFONO.USUARIO    := P_USUARIO;
    LR_REGISTRO_TELEFONO.PROGRAMA   := P_PROGRAMA;
    LR_REGISTRO_TELEFONO.CREADO_POR := LV_AGREGADO_POR;
    LR_REGISTRO_TELEFONO.CREADO_EN  := LV_AGREGADO_EN;
    INSERT INTO TELEFONOS VALUES LR_REGISTRO_TELEFONO;
END P_REGISTRAR_CLIENTE;
/

CREATE OR REPLACE PUBLIC SYNONYM P_REGISTRAR_CLIENTE FOR indra.P_REGISTRAR_CLIENTE;
GRANT EXECUTE ON P_REGISTRAR_CLIENTE TO PUBLIC;
