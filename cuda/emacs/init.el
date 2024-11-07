;; Tab = space x 4
(setq-default c-basic-offset 4)      ; Cの基本インデントをスペース4個に設定
(setq-default python-indent-offset 4)
(setq-default indent-tabs-mode nil)  ; タブ文字ではなくスペースを使う

;; タブ幅を4に設定
(setq-default tab-width 4)
;; タブの代わりにスペースを使用
(setq-default indent-tabs-mode nil)

(add-hook 'c-mode-hook
          (lambda ()
            (setq tab-width 4)
            (setq indent-tabs-mode nil)))

;;;
(if (>= emacs-major-version 20)
    (progn
      (setq dayname-j-alist
           '(("Sun" . "日") ("Mon" . "月") ("Tue" . "火") ("Wed" . "水")
             ("Thu" . "木") ("Fri" . "金") ("Sat" . "土")))
      (setq display-time-string-forms
           '((format "%s年%s月%s日(%s) %s:%s %s"
                     year month day
                     (cdr (assoc dayname dayname-j-alist))
                     24-hours minutes
                     load)))
      ))
(display-time)

;;; 最終更新日の自動挿入
;;;   ファイルの先頭から 8 行以内に Time-stamp: <> または
;;;   Time-stamp: " " と書いてあれば、セーブ時に自動的に日付が挿入されます
(if (not (memq 'time-stamp write-file-hooks))
    (setq write-file-hooks
          (cons 'time-stamp write-file-hooks)))


;; --------------------------------------------------------
;;  cuda-mode
;; --------------------------------------------------------
(add-to-list 'load-path "~/.emacs.d/cuda-mode/")
(add-to-list 'load-path "~/.emacs.d/cuda-mode/compat/")
(require 'cuda-mode)
;; ファイル拡張子とモードの関連付け
(add-to-list 'auto-mode-alist '("\\.cu\\'" . cuda-mode))
(add-to-list 'auto-mode-alist '("\\.cuh\\'" . cuda-mode))

