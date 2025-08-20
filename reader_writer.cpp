#include "reader_writer.h"

namespace reader {
    uint32_t BE_readBuffer_VectorUnChar_to_UnInt32(std::vector<unsigned char>& buffer, size_t Start) {
        return
            (__int32)buffer[Start + 3] +
            ((__int32)buffer[Start + 2] << 8) +
            ((__int32)buffer[Start + 1] << 16) +
            ((__int32)buffer[Start] << 24);
    }

    uint32_t LE_readBuffer_VectorUnChar_to_UnInt32(std::vector<unsigned char>& buffer, size_t Start) {
        return
            (__int32)buffer[Start] +
            ((__int32)buffer[Start + 1] << 8) +
            ((__int32)buffer[Start + 2] << 16) +
            ((__int32)buffer[Start + 3] << 24);
    }

    uint64_t BE_readBuffer_VectorUnChar_to_UnInt64(std::vector<unsigned char>& buffer, size_t Start) {
        return
            (__int64)buffer[Start + 7] +
            ((__int64)buffer[Start + 6] << 8) +
            ((__int64)buffer[Start + 5] << 16) +
            ((__int64)buffer[Start + 4] << 24) +
            ((__int64)buffer[Start + 3] << 32) +
            ((__int64)buffer[Start + 2] << 40) +
            ((__int64)buffer[Start + 1] << 48) +
            ((__int64)buffer[Start] << 56);
    }

    uint64_t LE_readBuffer_VectorUnChar_to_UnInt64(std::vector<unsigned char>& buffer, size_t Start) {
        return
            (__int64)buffer[Start] +
            ((__int64)buffer[Start + 1] << 8) +
            ((__int64)buffer[Start + 2] << 16) +
            ((__int64)buffer[Start + 3] << 24) +
            ((__int64)buffer[Start + 4] << 32) +
            ((__int64)buffer[Start + 5] << 40) +
            ((__int64)buffer[Start + 6] << 48) +
            ((__int64)buffer[Start + 7] << 56);
    }
    std::string readBuffer_VectorUnChar_to_String(
        const std::vector<unsigned char>& buffer, size_t Start, size_t SizeOfString) {
        // �������� �� ����� �� �������
        if (Start + SizeOfString > buffer.size()) {
            throw ("Buffer read out of range!");
        }

        // ������ ������ �������� �� ������ ������
        return std::string(
            reinterpret_cast<const char*>(&buffer[Start]),
            SizeOfString
        );
    }
}
namespace writer {
    // ���������� uint16_t � Big-Endian ������� (2 �����)
    void appendBE16(std::vector<unsigned char>& vec, uint16_t value) {
        vec.push_back(static_cast<unsigned char>((value >> 8) & 0xFF));  // ������� ����
        vec.push_back(static_cast<unsigned char>(value & 0xFF));         // ������� ����
    }

    // ���������� uint16_t � Little-Endian ������� (2 �����)
    void appendLE16(std::vector<unsigned char>& vec, uint16_t value) {
        vec.push_back(static_cast<unsigned char>(value & 0xFF));         // ������� ����
        vec.push_back(static_cast<unsigned char>((value >> 8) & 0xFF));  // ������� ����
    }



    // ���������� uint32_t � Big-Endian �������
    void appendBE32(std::vector<unsigned char>& vec, uint32_t value) {
        vec.push_back(static_cast<unsigned char>((value >> 24) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 16) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 8) & 0xFF));
        vec.push_back(static_cast<unsigned char>(value & 0xFF));
    }

    // ���������� uint32_t � Little-Endian �������
    void appendLE32(std::vector<unsigned char>& vec, uint32_t value) {
        vec.push_back(static_cast<unsigned char>(value & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 8) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 16) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 24) & 0xFF));
    }
    


    // ���������� uint64_t � Big-Endian �������
    void appendBE64(std::vector<unsigned char>& vec, uint64_t value) {
        vec.push_back(static_cast<unsigned char>((value >> 56) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 48) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 40) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 32) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 24) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 16) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 8) & 0xFF));
        vec.push_back(static_cast<unsigned char>(value & 0xFF));
    }

    // ���������� uint64_t � Little-Endian �������
    void appendLE64(std::vector<unsigned char>& vec, uint64_t value) {
        vec.push_back(static_cast<unsigned char>(value & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 8) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 16) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 24) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 32) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 40) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 48) & 0xFF));
        vec.push_back(static_cast<unsigned char>((value >> 56) & 0xFF));
    }



    // ���������� ������ (��� �������� �����)
    void appendString(std::vector<unsigned char>& vec, const std::string& str) {
        vec.insert(vec.end(), str.begin(), str.end());
    }
}