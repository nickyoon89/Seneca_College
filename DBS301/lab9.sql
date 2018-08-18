DROP TABLE tblProductLab9;
DROP TABLE tblVendorLab9;

CREATE TABLE tblVendorLab9
(
VendorID Number(38) Primary Key,
VendorName VARCHAR2(35) NOT NULL,
VendorContact VARCHAR2(30),
VendorContactPhone VARCHAR2(14)
)
;

CREATE TABLE tblProductLab9
(
ProductID Number(38) Primary Key,
VendorID Number(38),
ProductDesc VARCHAR2(30) NOT NULL UNIQUE,
ProductCost Number(6,2) CHECK(ProductCost >0),
ProductSell Number(6,2),
Constraint SellGreaterThanCost CHECK(ProductSell >= ProductCost),
CONSTRAINT fk_tblProduct_VendorID FOREIGN KEY (VendorID) REFERENCES tblVendorLab9(VendorID)
)
;
