import React from "react";
import Qrcode from "../assets/QRcode.png";

const AdComponent = () => {
  return (
    <div className="card m-2 text-center" style={{ width: "18rem", border: "2px solid #28a745", padding: "10px" }}>
      <div className="card-body">
        <h5 className="card-title" style={{ color: "#28a745" }}>Support Us</h5>
        <p className="card-text">If you like our content, consider supporting us through a donation. Your generosity helps us keep bringing you the latest news.</p>
        <div className="d-flex justify-content-center">
          <img src={Qrcode} alt="Donate QR Code" style={{ width: "150px", height: "150px" }} />
        </div>
        <p className="card-text mt-2">Scan the QR code to donate</p>
      </div>
    </div>
  );
};

export default AdComponent;
